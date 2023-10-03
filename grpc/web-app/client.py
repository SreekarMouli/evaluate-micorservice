import json
import grpc
import communication_pb2
import communication_pb2_grpc

channel = grpc.insecure_channel('evaluate-app:50051')  # Replace with the server address

formula_evaluator_stub = communication_pb2_grpc.FormulaEvaluatorStub(channel)

def send_request(ast, data):
    request = communication_pb2.FormulaRequest(formula=ast, data=data)
    response = formula_evaluator_stub.EvaluateFormula(request)
    print("Result:", response.result)

print("Begin")

ast = {
    "+": [
        {
            "type": "FUNCTION",
            "id": "everMax",
            "args": [
                {
                    "type": "VARIABLE",
                    "id": "amount_1"
                },
                {
                    "type": "VARIABLE",
                    "id": "amount_2"
                }
            ]
        },
        {
            "-": [
                {
                    "type": "VARIABLE",
                    "id": "amount_3"
                },
                {
                    "*": [
                        {
                            "type": "VARIABLE",
                            "id": "amount_4"
                        },
                        {
                            "type": "VARIABLE",
                            "id": "amount_5"
                        }
                    ]
                }
            ]
        }
    ]
}

row = {
    "id": "1",
    "email": "user1@mail.com",
    "sale_date": "2023-01-01",
    "amount_1": 100,
    "amount_2": 80,
    "amount_3": 5,
    "amount_4": 6,
    "amount_5": 1,
}

send_request(json.dumps(ast), json.dumps(row))

print("End")
