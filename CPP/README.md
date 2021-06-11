# TensorFlow 2.5 in C++
Install bazel https://docs.bazel.build/versions/3.7.2/install.html <br>

![tools.png](tools.png)

Clone the TensorFlow repository and prepare include and lib directories
```
mkdir -p tensorflow/git/ tensorflow/include tensorflow/lib
cd tensorflow/git
git clone --recursive --branch r2.5 https://github.com/tensorflow/tensorflow
cd tensorflow
```

Configure the bazel build in the tensorflow directory
```
./configure
```

building with bazel (make sure you are in bash) <br>
Build Dynamic-link libray (dll)
```
bazel build --config=opt --config=cuda tensorflow:tensorflow.dll
```

Build static import libraries (.lib)
```
bazel build --config=opt --config=cuda tensorflow:tensorflow.lib
```

Build header files
```
bazel build --config=opt --config=cuda tensorflow:install_headers
```

Copy `tensorflow.dll` and `tensorflow.lib` from `bazel-bin\tensorflow` to the lib folder. Lastly, copy the headers to the include folder.
```
cp bazel-bin/tensorflow/tensorflow.dll ../../lib/
cp bazel-bin/tensorflow/tensorflow.lib ../../lib/
cp -r bazel-bin/tensorflow/include/tensorflow/ ../../include/
```
> After building the code with bazel, you might want to delete the 20GB of cached build files in your home directory under `C:\Users\USER\_bazel_USER`, where `USER` is your computer username.

Running the code should output:
```
2021-06-11 11:02:34.147258: I tensorflow/stream_executor/platform/default/dso_loader.cc:53] Successfully opened dynamic library cudart64_110.dll
C++ TensorFlow version: 2.5.0, Git version: v2.5.0-17-g15d5b930d7e  
```