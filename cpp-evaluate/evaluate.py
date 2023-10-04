import time
import json
import pandas as pd

def plus(*args):
    return args[0] + args[1]

def minus(*args):
    return args[0] - args[1]

def multiply(*args):
    return args[0] * args[1]

def everMax(*args):
    return max(args)

def handle_variable(tok, row):
    key = tok["id"]
    val = row.get(key)
    return val

def handle_function(tok, row):
    func = tok["id"]
    args = tok["args"]
    args = [
        evaluate(arg, row) for arg in args
    ]
    if func == "everMax":
        return everMax(*args)
    return 0

def handle_operator(operator, values, row):
    values = [
        evaluate(val, row) for val in values
    ]
    if operator == "+":
        return plus(*values)
    elif operator == "-":
        return minus(*values)
    elif operator == "*":
        return multiply(*values)
    return 0

def evaluate(ast, row):
    if isinstance(ast, dict) and ast.get("type") == "VARIABLE":
        return handle_variable(ast, row)
    if isinstance(ast, dict) and ast.get("type") == "FUNCTION":
        return handle_function(ast, row)
    operator = list(ast.keys())[0]
    return handle_operator(operator, ast[operator], row)

def bulk_evaluate(ast, data):
    df = pd.DataFrame(data)
    res = []
    print("BEGIN")
    t1 = time.time()
    res = df.apply(lambda row: evaluate(ast, row), axis=1)
    t2 = time.time()
    print("END, Time taken: ", t2 - t1)


if __name__ == "__main__":
    print("loading ast")
    with open("sample_ast.json") as f:
        ast = json.load(f)
    print("loading ast done", ast)
    print("loading data")
    with open("large_data.json") as f:
        data = json.load(f)
    print("loading data done")
    bulk_evaluate(ast, data)
