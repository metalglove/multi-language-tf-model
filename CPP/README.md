# TensorFlow 2.5 in C++
Install bazel https://docs.bazel.build/versions/3.7.2/install.html <br>
Install CUDA https://developer.download.nvidia.com/compute/cuda/11.2.2/local_installers/cuda_11.2.2_461.33_win10.exe <br>
Install cuDNN https://developer.nvidia.com/compute/machine-learning/cudnn/secure/8.1.1.33/11.2_20210301/cudnn-11.2-windows-x64-v8.1.1.33.zip <br>
Unzip and move cudnn libraries to cuda folder.
Copy `downloadpath\cuda\bin\cudnn*.dll` to `C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.2\bin`.
Copy `downloadpath\cuda\include\cudnn*.h` to `C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.2\include`.
Copy `downloadpath\cuda\lib\x64\cudnn*.lib` to `C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.2\lib\x64`.

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
cp bazel-bin/tensorflow/tensorflow.dll ../../lib/
cp bazel-bin/tensorflow/tensorflow.lib ../../lib/
cp bazel-bin/tensorflow/include/tensorflow/ ../../include/
```