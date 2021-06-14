#define NDEBUG
#define _CONSOLE
#define NOMINMAX
#define COMPILER_MSVC

#include <tensorflow/core/public/version.h>
#include <tensorflow/cc/saved_model/loader.h>
#include <tensorflow/cc/saved_model/tag_constants.h>
#include <tensorflow/cc/ops/standard_ops.h>
#include <tensorflow/cc/client/client_session.h>
#include <tensorflow/core/framework/tensor.h>
#include "../../../CPP/matplotlibcpp.h"
#include <iostream>
#include <fstream>

namespace plt = matplotlibcpp;
using namespace tensorflow;
using namespace std;

vector<float> EigenTensorToVector(Eigen::TensorMap<Eigen::Tensor<float, 1, 1, Eigen::DenseIndex>, 16> tensor) {
	float* data = tensor.data();
	return std::vector(data, data + tensor.size());
}

vector<pair<string, vector<float>>> ReadCSV(string filename) {
    // Reads a CSV file into a vector of <string, vector<float>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, float vector> pairs to store the result
    vector<pair<string, vector<float>>> result;

    // Create an input filestream
    ifstream myFile(filename);

    // Make sure the file is open
    if (!myFile.is_open()) 
		throw runtime_error("Could not open file");

    // Helper vars
    string line, colname;
    float val;

    // Read the column names
    if (myFile.good())
    {
        // Extract the first line in the file
        getline(myFile, line);

        // Create a stringstream from line
        stringstream ss(line);

        // Extract each column name
        while (getline(ss, colname, ';')) {

            // Initialize and add <colname, float vector> pairs to result
            result.push_back({ colname, vector<float> {} });
        }
    }

    // Read data, line by line
    while (getline(myFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each float
        while (ss >> val) {

            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            // If the next token is a semicolon, ignore it and move on
            if (ss.peek() == ';') 
				ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    return result;
}


int main(int argc, char* argv[]) {
	cout << "C++ TensorFlow version: " << TF_VERSION_STRING << ", Git version: " << tf_git_version() << endl;

	/*
	--- Example code for building a graph ---
	
	Scope scope = Scope::NewRootScope();
	auto seed = ops::RandomNormal::Seed(56);
	auto seed2 = ops::RandomNormal::Seed(57);

	auto TRUE_W = ops::Const(scope, 3.0f, { 1, 1 });
	auto TRUE_B = ops::Const(scope, 2.0f, { 1, 1 });

	auto x = ops::RandomNormal(scope, { 1000, 1 }, DT_FLOAT, ops::RandomNormal::Seed(56));
	auto noise = ops::RandomNormal(scope, { 1000, 1 }, DT_FLOAT, seed2);
	auto W = ops::MatMul(scope, x, TRUE_W);
	auto b = ops::Add(scope, TRUE_B, noise);
	auto y = ops::Add(scope, W, b);

	ClientSession session(scope);
	vector<Tensor> outputs;
	Status status = session.Run({ x, y }, &outputs);

	TF_CHECK_OK(status);
	
	vector<float> xvec = EigenTensorToVector(outputs[0].flat<float>());
	vector<float> yvec = EigenTensorToVector(outputs[1].flat<float>());
	
	plt::scatter(xvec, yvec, 1.0, { {"color", "blue"} });
	plt::show();
	*/

	auto data = ReadCSV("../../../../dataset.csv");
	vector<float> xvec = data[0].second;
	vector<float> yvec = data[1].second;

	SavedModelBundle model;
	SessionOptions session_options;
	RunOptions run_options;
	Status status = LoadSavedModel(session_options, run_options, "../../../../LinearRegressionModel/", { kSavedModelTagServe }, &model);
	
	if (!status.ok())
	{
		cout << status.ToString() << endl;
		return 1;
	}

	Tensor tensor(DT_FLOAT, { 1000 });
	copy(xvec.begin(), xvec.end(), tensor.flat<float>().data());
	vector<Tensor> outputs;
	Status inference_status = model.GetSession()->Run({ { "serving_default_x:0", tensor } }, { "StatefulPartitionedCall:0" }, { "StatefulPartitionedCall:0" }, &outputs);

	if (!inference_status.ok())
	{
		cout << inference_status.ToString() << endl;
		return 1;
	}

	vector<float> pred_yvec = EigenTensorToVector(outputs[0].flat<float>());

	plt::figure();
	plt::title("C++ inference using 'SavedModel' API", {});
	plt::scatter(xvec, yvec, 1.0, { {"color", "blue"} });
	plt::plot(xvec, pred_yvec, { {"color", "red"} });
	plt::show();

	return 0;
}