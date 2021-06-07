# TensorFlow 2.5 in C++
Install bazel https://docs.bazel.build/versions/4.1.0/install.html <br>
Install needed tools
![tools.png](tools.png)

Clone the TensorFlow repository
```
mkdir -p tensorflow/git/
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
cp bazel-bin/tensorflow/include/tensorflow/tensorflow.dll ../../lib/
cp bazel-bin/tensorflow/include/tensorflow/tensorflow.lib ../../lib/
cp bazel-bin/tensorflow/include/tensorflow/ ../../include/
```