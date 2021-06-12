#define NDEBUG
#define _CONSOLE
#define NOMINMAX
#define COMPILER_MSVC

#include <iostream>
#include <tensorflow/cc/client/client_session.h>
#include <tensorflow/cc/ops/array_ops.h>
#include <tensorflow/cc/ops/math_ops.h>
#include <tensorflow/core/public/version.h>

using namespace tensorflow;
using namespace std;

int main(int argc, char* argv[]) {
	cout << "C++ TensorFlow version: " << TF_VERSION_STRING << ", Git version: " << tf_git_version() << endl;

	Scope root = Scope::NewRootScope();
	auto a = ops::Placeholder(root, DT_INT32);
	auto c = ops::Add(root, a, { 5 });

	ClientSession session(root);
	vector<Tensor> outputs;

	Status status = session.Run({ {a, { 3 } } }, { c }, &outputs);

	if (!status.ok())
	{
		cout << status.ToString() << endl;
		return 1;
	}

	cout << "---------------------------------" << endl;
	cout << "5 + 3 = " << outputs[0].scalar<int>() << endl;
	cout << "---------------------------------" << endl;
	return 0;
}