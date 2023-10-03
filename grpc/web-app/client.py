import grpc
import communication_pb2
import communication_pb2_grpc

channel = grpc.insecure_channel('localhost:50051')  # Replace with the server address

formula_evaluator_stub = communication_pb2_grpc.FormulaEvaluatorStub(channel)

def send_request(ast, data):
    request = communication_pb2.FormulaRequest(formula=ast, data=data)
    response = formula_evaluator_stub.EvaluateFormula(request)
    print("Result:", response.result)

print("Running...")