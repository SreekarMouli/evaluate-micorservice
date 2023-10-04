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
        std::cout << "received request" << std::endl;
        std::string formula = request->formula();
        std::string data = request->data();
        std::cout << "ast: " << formula << std::endl;
        std::cout << "data length: " << data.length() << std::endl;
        json formula_json = json::parse(formula);
        std::cout << "converting data to json" << std::endl;
        json data_json = json::parse(data);
        std::cout << "conversion done" << std::endl;
        std::vector<int> result = bulk_evaluate(formula_json, data_json);
        std::cout << "obtained result" << std::endl;
        nlohmann::json result_json(result);
        std::string result_json_string = result_json.dump();
        response->set_result(result_json_string);
        return Status::OK;
    }
};

int main() {
    std::string server_address("0.0.0.0:50051");  // Replace with your desired server address

    FormulaEvaluatorImpl service;

    ServerBuilder builder;
    builder.SetMaxReceiveMessageSize(200 * 1024 * 1024);  // 200MB
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
    
    return 0;
}
