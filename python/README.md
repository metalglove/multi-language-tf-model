# TensorFlow 2.5 in Python 3
The Python version of the multi model script is used to create a LinearRegressionModel for a set of predefined parameters.
This model is saved using the `SavedModel` API to be used in other languages.

## Setup
Create the virtual environment.
```
python -m venv tf2.5-env
```

Active the environment.
```
source tf2.5-env/Scripts/activate
```
> NOTE: When on Windows run `tf2.5-env\Scripts\activate` instead (without source).

Install the python requirements
```
python -m pip install -r requirements.txt
```

## Running the code
Running the code should print out the TensorFlow version, the training loop, and a Matplotlib figure presenting the LinearRegressionModel and synthetic data:
```
2021-06-14 03:03:05.679769: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cudart64_110.dll
Python TensorFlow version: 2.5.0
2021-06-14 03:03:09.179842: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library nvcuda.dll
2021-06-14 03:03:09.206775: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1733] Found device 0 with properties: 
pciBusID: 0000:01:00.0 name: GeForce RTX 2080 computeCapability: 7.5
coreClock: 1.815GHz coreCount: 46 deviceMemorySize: 8.00GiB deviceMemoryBandwidth: 417.23GiB/s
2021-06-14 03:03:09.206922: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cudart64_110.dll
2021-06-14 03:03:09.216015: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cublas64_11.dll
2021-06-14 03:03:09.216102: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cublasLt64_11.dll
2021-06-14 03:03:09.218889: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cufft64_10.dll
2021-06-14 03:03:09.219951: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library curand64_10.dll
2021-06-14 03:03:09.223965: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cusolver64_11.dll
2021-06-14 03:03:09.226541: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cusparse64_11.dll
2021-06-14 03:03:09.227012: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cudnn64_8.dll
2021-06-14 03:03:09.227140: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1871] Adding visible gpu devices: 0
2021-06-14 03:03:09.228687: I tensorflow/core/platform/cpu_feature_guard.cc:142] This TensorFlow binary is optimized with oneAPI Deep Neural Network Library (oneDNN) to use the following CPU instructions in performance-critical operations:  AVX AVX2
To enable them in other operations, rebuild TensorFlow with the appropriate compiler flags.
2021-06-14 03:03:09.230067: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1733] Found device 0 with properties: 
pciBusID: 0000:01:00.0 name: GeForce RTX 2080 computeCapability: 7.5
coreClock: 1.815GHz coreCount: 46 deviceMemorySize: 8.00GiB deviceMemoryBandwidth: 417.23GiB/s
2021-06-14 03:03:09.230300: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1871] Adding visible gpu devices: 0
2021-06-14 03:03:09.659099: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1258] Device interconnect StreamExecutor with strength 1 edge matrix:
2021-06-14 03:03:09.659191: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1264]      0 
2021-06-14 03:03:09.659237: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1277] 0:   N 
2021-06-14 03:03:09.659421: I tensorflow/core/common_runtime/gpu/gpu_device.cc:1418] Created TensorFlow device (/job:localhost/replica:0/task:0/device:GPU:0 with 5961 MB memory) -> physical GPU (device: 0, name: GeForce RTX 2080, pci bus id: 0000:01:00.0, compute capability: 7.5)
2021-06-14 03:03:09.936248: I tensorflow/compiler/mlir/mlir_graph_optimization_pass.cc:176] None of the MLIR Optimization Passes are enabled (registered 2)
Epoch 1/10

1/1 [==============================] - ETA: 0s - loss: 8.7643
1/1 [==============================] - 0s 442ms/step - loss: 8.7643
Epoch 2/10

1/1 [==============================] - ETA: 0s - loss: 6.0225
1/1 [==============================] - 0s 2ms/step - loss: 6.0225
Epoch 3/10

1/1 [==============================] - ETA: 0s - loss: 4.2452
1/1 [==============================] - 0s 1ms/step - loss: 4.2452
Epoch 4/10

1/1 [==============================] - ETA: 0s - loss: 3.0929
1/1 [==============================] - 0s 1ms/step - loss: 3.0929
Epoch 5/10

1/1 [==============================] - ETA: 0s - loss: 2.3455
1/1 [==============================] - 0s 2ms/step - loss: 2.3455
Epoch 6/10

1/1 [==============================] - ETA: 0s - loss: 1.8606
1/1 [==============================] - 0s 1ms/step - loss: 1.8606
Epoch 7/10

1/1 [==============================] - ETA: 0s - loss: 1.5460
1/1 [==============================] - 0s 1ms/step - loss: 1.5460
Epoch 8/10

1/1 [==============================] - ETA: 0s - loss: 1.3417
1/1 [==============================] - 0s 998us/step - loss: 1.3417
Epoch 9/10

1/1 [==============================] - ETA: 0s - loss: 1.2091
1/1 [==============================] - 0s 2ms/step - loss: 1.2091
Epoch 10/10

1/1 [==============================] - ETA: 0s - loss: 1.1229
1/1 [==============================] - 0s 1ms/step - loss: 1.1229
Saving LinearRegressionModel...
2021-06-14 03:03:12.105915: W tensorflow/python/util/util.cc:348] Sets are not currently considered sequences, but this may change in the future, so consider avoiding using them.
Saved LinearRegressionModel!
Saving generated dataset...
Saved generated dataset!

MetaGraphDef with tag-set: 'serve' contains the following SignatureDefs:

signature_def['__saved_model_init_op']:
  The given SavedModel SignatureDef contains the following input(s):
  The given SavedModel SignatureDef contains the following output(s):
    outputs['__saved_model_init_op'] tensor_info:
        dtype: DT_INVALID
        shape: unknown_rank
        name: NoOp
  Method name is: 

signature_def['serving_default']:
  The given SavedModel SignatureDef contains the following input(s):
    inputs['x'] tensor_info:
        dtype: DT_FLOAT
        shape: unknown_rank
        name: serving_default_x:0
  The given SavedModel SignatureDef contains the following output(s):
    outputs['output'] tensor_info:
        dtype: DT_FLOAT
        shape: unknown_rank
        name: StatefulPartitionedCall:0
  Method name is: tensorflow/serving/predict

Defined Functions:
  Function Name: '__call__'
    Option #1
      Callable with:
        Argument #1
          x: TensorSpec(shape=<unknown>, dtype=tf.float32, name='x')

  Function Name: '_default_save_signature'
    Option #1
      Callable with:
        Argument #1
          args_0: TensorSpec(shape=<unknown>, dtype=tf.float32, name='args_0')

  Function Name: 'call'
    Option #1
      Callable with:
        Argument #1
          x: TensorSpec(shape=<unknown>, dtype=tf.float32, name='x')

  Function Name: 'call_and_return_all_conditional_losses'
    Option #1
      Callable with:
        Argument #1
          x: TensorSpec(shape=<unknown>, dtype=tf.float32, name='x')
```
And the Matplotlib Figure should look like this, synthetic data in blue and regression in red:
![Linear Regression Model Figure](LinearRegressionModel_Figure.png)
> NOTE: The `SavedModel` is saved in the root directory of the repository when run from Visual Studio.
> The CPP script expects to find the model in the root directory too. 
> If you have ran `main.py` from the terminal in the `python` directory, then the model is saved in the `python` directory.
> So, try running it from the root directory `python ./python/main.py`.
## Sources used
https://www.tensorflow.org/guide/saved_model