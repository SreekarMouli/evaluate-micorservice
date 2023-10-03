#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "communication.grpc.pb.h"
#include "communication.pb.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using communication::FormulaRequest;
using communication::FormulaResponse;
using communication::FormulaEvaluator;

// Implement your service logic here
class FormulaEvaluatorImpl final : public FormulaEvaluator::Service {
    Status EvaluateFormula(ServerContext* context, const FormulaRequest* request, FormulaResponse* response) override {
        // Implement your formula evaluation logic here based on the request
        // Set the result in the response
        response->set_result("42");  // Replace with your actual calculation
        return Status::OK;
    }
};

int main() {
    std::string server_address("0.0.0.0:50051");  // Replace with your desired server address

    FormulaEvaluatorImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
    
    return 0;
}
