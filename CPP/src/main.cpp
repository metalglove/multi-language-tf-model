#include <iostream>
#include <tensorflow/core/public/version.h>

using namespace std;

int main()
{
  cout << tf_git_version() << endl;
  return 0;
}
