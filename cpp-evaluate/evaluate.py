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

def handle_operator(operator, *values):
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
    return handle_operator(operator, *ast[operator])


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
res = evaluate(ast, row)
print(res)