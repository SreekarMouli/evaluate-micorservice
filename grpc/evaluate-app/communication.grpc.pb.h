// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: communication.proto
#ifndef GRPC_communication_2eproto__INCLUDED
#define GRPC_communication_2eproto__INCLUDED

#include "communication.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

class FormulaEvaluator final {
 public:
  static constexpr char const* service_full_name() {
    return "FormulaEvaluator";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest& request, ::FormulaResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::FormulaResponse>> AsyncEvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::FormulaResponse>>(AsyncEvaluateFormulaRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::FormulaResponse>> PrepareAsyncEvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::FormulaResponse>>(PrepareAsyncEvaluateFormulaRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest* request, ::FormulaResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest* request, ::FormulaResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::FormulaResponse>* AsyncEvaluateFormulaRaw(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::FormulaResponse>* PrepareAsyncEvaluateFormulaRaw(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest& request, ::FormulaResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::FormulaResponse>> AsyncEvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::FormulaResponse>>(AsyncEvaluateFormulaRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::FormulaResponse>> PrepareAsyncEvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::FormulaResponse>>(PrepareAsyncEvaluateFormulaRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest* request, ::FormulaResponse* response, std::function<void(::grpc::Status)>) override;
      void EvaluateFormula(::grpc::ClientContext* context, const ::FormulaRequest* request, ::FormulaResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::FormulaResponse>* AsyncEvaluateFormulaRaw(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::FormulaResponse>* PrepareAsyncEvaluateFormulaRaw(::grpc::ClientContext* context, const ::FormulaRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_EvaluateFormula_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status EvaluateFormula(::grpc::ServerContext* context, const ::FormulaRequest* request, ::FormulaResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_EvaluateFormula : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_EvaluateFormula() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_EvaluateFormula() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status EvaluateFormula(::grpc::ServerContext* /*context*/, const ::FormulaRequest* /*request*/, ::FormulaResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestEvaluateFormula(::grpc::ServerContext* context, ::FormulaRequest* request, ::grpc::ServerAsyncResponseWriter< ::FormulaResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_EvaluateFormula<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_EvaluateFormula : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_EvaluateFormula() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::FormulaRequest, ::FormulaResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::FormulaRequest* request, ::FormulaResponse* response) { return this->EvaluateFormula(context, request, response); }));}
    void SetMessageAllocatorFor_EvaluateFormula(
        ::grpc::MessageAllocator< ::FormulaRequest, ::FormulaResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::FormulaRequest, ::FormulaResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_EvaluateFormula() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status EvaluateFormula(::grpc::ServerContext* /*context*/, const ::FormulaRequest* /*request*/, ::FormulaResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* EvaluateFormula(
      ::grpc::CallbackServerContext* /*context*/, const ::FormulaRequest* /*request*/, ::FormulaResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_EvaluateFormula<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_EvaluateFormula : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_EvaluateFormula() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_EvaluateFormula() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status EvaluateFormula(::grpc::ServerContext* /*context*/, const ::FormulaRequest* /*request*/, ::FormulaResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_EvaluateFormula : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_EvaluateFormula() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_EvaluateFormula() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status EvaluateFormula(::grpc::ServerContext* /*context*/, const ::FormulaRequest* /*request*/, ::FormulaResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestEvaluateFormula(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_EvaluateFormula : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_EvaluateFormula() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->EvaluateFormula(context, request, response); }));
    }
    ~WithRawCallbackMethod_EvaluateFormula() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status EvaluateFormula(::grpc::ServerContext* /*context*/, const ::FormulaRequest* /*request*/, ::FormulaResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* EvaluateFormula(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_EvaluateFormula : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_EvaluateFormula() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::FormulaRequest, ::FormulaResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::FormulaRequest, ::FormulaResponse>* streamer) {
                       return this->StreamedEvaluateFormula(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_EvaluateFormula() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status EvaluateFormula(::grpc::ServerContext* /*context*/, const ::FormulaRequest* /*request*/, ::FormulaResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedEvaluateFormula(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::FormulaRequest,::FormulaResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_EvaluateFormula<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_EvaluateFormula<Service > StreamedService;
};


#endif  // GRPC_communication_2eproto__INCLUDED
