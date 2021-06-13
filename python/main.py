import tensorflow as tf
from tensorflow.keras.optimizers import SGD
from tensorflow.keras.losses import MSE
import matplotlib.pyplot as plt

class LinearRegression(tf.keras.Model):
    def __init__(self):
        super(LinearRegression, self).__init__()
        self.w = tf.Variable(5.0)
        self.b = tf.Variable(0.0)
    
    @tf.function
    def call(self, x):
        return self.w * x + self.b

if __name__ == '__main__':
    print('Python TensorFlow version: ' + tf.version.VERSION)
    tf.random.set_seed(56)

    TRUE_W = 3.0
    TRUE_B = 2.0
    NUM_EXAMPLES = 1000

    x = tf.random.normal(shape = [NUM_EXAMPLES])
    noise = tf.random.normal(shape = [NUM_EXAMPLES])
    y = x * TRUE_W + TRUE_B + noise

    linearRegressionModel = LinearRegression()
    linearRegressionModel.compile(optimizer = SGD(learning_rate = 0.1), loss = MSE)
    linearRegressionModel.fit(x, y, epochs = 10, batch_size = 1000)

    plt.scatter(x, y, c = 'b')
    plt.scatter(x, linearRegressionModel(x), c = 'r')
    plt.show()

    print('Saving LinearRegressionModel...')
    linearRegressionModel.save(filepath = 'LinearRegressionModel', overwrite = True)
    print('Saved LinearRegressionModel!')
    
    linearRegressionModel.summary()




