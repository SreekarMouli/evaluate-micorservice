// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: communication.proto

#include "communication.pb.h"
#include "communication.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* FormulaEvaluator_method_names[] = {
  "/FormulaEvaluator/EvaluateFormula",
};

std::unique_ptr< FormulaEvaluator::Stub> FormulaEvaluator::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< FormulaEvaluator::Stub> stub(new FormulaEvaluator::Stub(channel, options));
  return stub;
}

FormulaEvaluator::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_EvaluateFormula_(FormulaEvaluator_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status FormulaEvaluator::Stub::EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest& request, ::FormulaResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::FormulaRequest, ::FormulaResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_EvaluateFormula_, context, request, response);
}

void FormulaEvaluator::Stub::async::EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest* request, ::FormulaResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::FormulaRequest, ::FormulaResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EvaluateFormula_, context, request, response, std::move(f));
}

void FormulaEvaluator::Stub::async::EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest* request, ::FormulaResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EvaluateFormula_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::FormulaResponse>* FormulaEvaluator::Stub::PrepareAsyncEvaluateFormulaRaw(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::FormulaResponse, ::FormulaRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_EvaluateFormula_, context, request);
}

::grpc::ClientAsyncResponseReader< ::FormulaResponse>* FormulaEvaluator::Stub::AsyncEvaluateFormulaRaw(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncEvaluateFormulaRaw(context, request, cq);
  result->StartCall();
  return result;
}

FormulaEvaluator::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FormulaEvaluator_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FormulaEvaluator::Service, ::FormulaRequest, ::FormulaResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FormulaEvaluator::Service* service,
             ::grpc::ServerContext* ctx,
             const ::FormulaRequest* req,
             ::FormulaResponse* resp) {
               return service->EvaluateFormula(ctx, req, resp);
             }, this)));
}

FormulaEvaluator::Service::~Service() {
}

::grpc::Status FormulaEvaluator::Service::EvaluateFormula(::grpc::ServerContext* context, const ::FormulaRequest* request, ::FormulaResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


