import tensorflow as tf
from tensorflow.keras.optimizers import SGD
from tensorflow.keras.losses import MSE
from tensorflow.keras.layers import Dense, Input
import matplotlib.pyplot as plt
import pandas as pd
from tensorflow.python.tools import saved_model_cli

class LinearRegression(tf.keras.Model):
    def __init__(self):
        super(LinearRegression, self).__init__()
        self.w = tf.Variable(5.0)
        self.b = tf.Variable(0.0)
    
    @tf.function(input_signature=[tf.TensorSpec(None, tf.float32)])
    def call(self, x):
        return { 'output': self.w * x + self.b }

if __name__ == '__main__':
    print('Python TensorFlow version: ' + tf.version.VERSION)
    
    TRUE_W = 3.0
    TRUE_B = 2.0
    NUM_EXAMPLES = 1000

    x = tf.random.normal(shape = [NUM_EXAMPLES], seed = 56)
    noise = tf.random.normal(shape = [NUM_EXAMPLES], seed = 57)
    y = x * TRUE_W + TRUE_B + noise

    linearRegressionModel = LinearRegression()
    linearRegressionModel.compile(optimizer = SGD(learning_rate = 0.1), loss = MSE)
    linearRegressionModel.fit(x, y, epochs = 10, batch_size = 1000)

    plt.figure()
    plt.title('Python inference using trained model')
    plt.scatter(x, y, s = 1.0, c = 'b')
    plt.plot(x, linearRegressionModel(x)["output"], c = 'r')
    plt.show()

    print('Saving LinearRegressionModel...')
    call = linearRegressionModel.call.get_concrete_function(tf.TensorSpec(None, tf.float32))
    signatures = { 'serving_default': call }
    linearRegressionModel.save(filepath = 'LinearRegressionModel', signatures = signatures, overwrite = True)
    print('Saved LinearRegressionModel!')
    
    print('Saving generated dataset...')
    df = pd.DataFrame({ 'x': x, 'y': y.numpy() })
    df.to_csv('dataset.csv', sep = ';', index = False)
    print('Saved generated dataset!')

    # print the input and output op names from the MetaGraph
    class Args(object):
        pass

    args = Args()
    args.dir = 'LinearRegressionModel'
    args.all = True
    saved_model_cli.show(args)




