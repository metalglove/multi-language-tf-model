#include <iostream>
#include <tensorflow/core/public/version.h>

using namespace std;

int main()
{
  cout << "C++ TensorFlow version: " << TF_VERSION_STRING << ", Git version: " << tf_git_version() << endl;
  return 0;
}
