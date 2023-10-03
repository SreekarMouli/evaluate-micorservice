/* Evaluate Service written in cuda-cpp for execution on Nvidia GPUs  */
#include <iostream>
#include <nlohmann/json.hpp>
#include <cuda_runtime.h>

using json = nlohmann::json;

__device__ float plus(float a, float b) {
    return a + b;
}

__device__ float minus(float a, float b) {
    return a - b;
}

__device__ float multiply(float a, float b) {
    return a * b;
}

__device__ float handle_variable(const json& row, const std::string& key) {
    if (row.find(key) != row.end()) {
        return row[key].get<float>();
    }
    return 0.0; // Default value if variable is not found
}

template <typename T>
__global__ void evaluateFormula(const char* formulaJson, const char* rowsJson, T* results, int numRows) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    if (tid < numRows) {
        json ast = json::parse(formulaJson);
        json row = json::parse(rowsJson); // Parse the row as a JSON object

        // Parse the JSON AST dynamically and evaluate the formula for row 'tid'
        T result = 0.0; // Initialize with the neutral element

        // Traverse the JSON AST and apply operations dynamically
        for (const auto& item : ast) {
            if (item.is_object()) {
                const std::string& operator_str = item.begin().key();
                const json& operands = item.begin().value();

                if (operator_str == "+") {
                    result = plus(result, operands[0].is_string() ? handle_variable(row, operands[0]) : operands[0].get<float>());
                } else if (operator_str == "-") {
                    result = minus(result, operands[0].is_string() ? handle_variable(row, operands[0]) : operands[0].get<float>());
                } else if (operator_str == "*") {
                    result = multiply(result, operands[0].is_string() ? handle_variable(row, operands[0]) : operands[0].get<float>());
                }
            }
        }

        results[tid] = result; // Store the result in the results array
    }
}

int main() {
    // Initialize CUDA
    cudaError_t cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        std::cerr << "CUDA initialization failed!" << std::endl;
        return 1;
    }

    // Define problem size
    int numRows = 1; // Adjust as needed
    int blockSize = 1; // Adjust as needed

    // Allocate memory on the CPU for results
    float* results = new float[numRows];

    // Convert the JSON AST and row data to strings
    std::string formulaJson = "{\"+\": [\"a\", {\"-\": [\"b\", {\"*\": [\"c\", \"d\"]}]}]}";
    std::string rowJson = "{\"a\": 1.0, \"b\": 2.0, \"c\": 3.0, \"d\": 4.0}";

    const char* formulaJsonCStr = formulaJson.c_str();
    const char* rowJsonCStr = rowJson.c_str();

    // Allocate memory on the GPU for results
    float* d_results;
    cudaStatus = cudaMalloc((void**)&d_results, numRows * sizeof(float));
    if (cudaStatus != cudaSuccess) {
        std::cerr << "CUDA memory allocation failed!" << std::endl;
        delete[] results;
        return 1;
    }

    // Launch the CUDA kernel
    evaluateFormula<float><<<numRows, blockSize>>>(formulaJsonCStr, rowJsonCStr, d_results, numRows);

    // Check for kernel launch errors
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        std::cerr << "CUDA kernel launch failed: " << cudaGetErrorString(cudaStatus) << std::endl;
        cudaFree(d_results);
        delete[] results;
        return 1;
    }

    // Copy results from GPU to CPU
    cudaStatus = cudaMemcpy(results, d_results, numRows * sizeof(float), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        std::cerr << "CUDA memcpy failed: " << cudaGetErrorString(cudaStatus) << std::endl;
        cudaFree(d_results);
        delete[] results;
        return 1;
    }

    // Print or use the result
    std::cout << "Result: " << results[0] << std::endl;

    // Cleanup
    cudaFree(d_results);
    delete[] results;

    return 0;
}
