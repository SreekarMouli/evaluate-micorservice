import time
import json
import grpc
import communication_pb2
import communication_pb2_grpc

channel = grpc.insecure_channel('evaluate-app:50051', options=[
    ('grpc.max_send_message_length', 200 * 1024 * 1024),  # 200MB
    ('grpc.max_receive_message_length', 200 * 1024 * 1024),  # 200MB
])

formula_evaluator_stub = communication_pb2_grpc.FormulaEvaluatorStub(channel)

def send_request(ast, data):
    request = communication_pb2.FormulaRequest(formula=ast, data=data)
    t1 = time.time()
    formula_evaluator_stub.EvaluateFormula(request)
    t2 = time.time()
    print("Time taken:", t2 - t1)

if __name__ == "__main__":
    print("begin")
    print("loading ast")
    with open("sample_ast.json") as f:
        ast = f.read()
    print("loading ast done", ast)
    print("loading data")
    with open("large_data.json") as f:
        data = f.read()
    print("loading data done")
    send_request(ast, data)
    print("end")
