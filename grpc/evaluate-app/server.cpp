#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "communication.grpc.pb.h"
#include "communication.pb.h"
#include "nlohmann/json.hpp"
#include "evaluate.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using communication::FormulaRequest;
using communication::FormulaResponse;
using communication::FormulaEvaluator;
using json = nlohmann::json;

// Implement your service logic here
class FormulaEvaluatorImpl final : public FormulaEvaluator::Service {
    Status EvaluateFormula(ServerContext* context, const FormulaRequest* request, FormulaResponse* response) override {
        std::string formula = request->formula();
        std::string row = request->data();
        std::cout << "Received ast: " << formula << std::endl;
        std::cout << "Received row: " << row << std::endl;
        json ast;
        json rowData;
        try {
            ast = json::parse(formula);
            rowData = json::parse(row);
        } catch (json::parse_error& e) {
            std::cerr << "Error parsing JSON data: " << e.what() << std::endl;
            return Status(grpc::INVALID_ARGUMENT, "Invalid JSON data");
        }
        int result = evaluate(ast, rowData);
        response->set_result(std::to_string(result));
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
