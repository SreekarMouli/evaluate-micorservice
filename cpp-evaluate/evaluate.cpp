#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int evaluate(json &ast, json &row);

int plus(int arg1, int arg2)
{
    return arg1 + arg2;
}
int minus(int arg1, int arg2)
{
    return arg1 - arg2;
}
int multiply(int arg1, int arg2)
{
    return arg1 * arg2;
}
int everMax(std::vector<int> &args)
{
    if (args.empty())
    {
        return 0;
    }
    return *std::max_element(args.begin(), args.end());
}
int handle_variable(json &tok, json &row)
{
    std::string key = tok["id"];
    if (row.find(key) != row.end())
    {
        return row[key];
    }
    return 0;
}
int handle_function(json &tok, json &row)
{
    std::string func = tok["id"];
    json &args = tok["args"];
    std::vector<int> evaluated_args;
    for (auto &arg : args)
    {
        if (arg.is_object() && arg["type"] == "VARIABLE")
        {
            evaluated_args.push_back(handle_variable(arg, row));
        }
    }
    if (func == "everMax")
    {
        return everMax(evaluated_args);
    }
    return 0;
}
int handle_operator(std::string operator_str, json &values, json &row)
{
    std::vector<int> evaluated_values;
    for (auto &val : values)
    {
        evaluated_values.push_back(evaluate(val, row));
    }
    if (operator_str == "+")
    {
        return plus(evaluated_values[0], evaluated_values[1]);
    }
    else if (operator_str == "-")
    {
        return minus(evaluated_values[0], evaluated_values[1]);
    }
    else if (operator_str == "*")
    {
        return multiply(evaluated_values[0], evaluated_values[1]);
    }
    return 0;
}
int evaluate(json &ast, json &row)
{
    if (ast.is_object() && ast["type"] == "VARIABLE")
    {
        return handle_variable(ast, row);
    }
    if (ast.is_object() && ast["type"] == "FUNCTION")
    {
        return handle_function(ast, row);
    }
    std::string operator_str;
    operator_str = ast.begin().key();
    json &values = ast[operator_str];
    return handle_operator(operator_str, values, row);
}
void bulk_evaluate(json &ast, json &rows)
{
    std::vector<int> results;
    std::cout << "BEGIN" << std::endl;
    int t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for (auto &row : rows)
    {
        results.push_back(evaluate(ast, row));
    }
    int t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "END, Time Taken: " << (t2 - t1) / 1000 << std::endl;
}
int main()
{
    // json row = {
    //     {"id", "1"},
    //     {"email", "user1@mail.com"},
    //     {"sale_date", "2023-01-01"},
    //     {"amount_1", 100},
    //     {"amount_2", 80},
    //     {"amount_3", 5},
    //     {"amount_4", 6},
    //     {"amount_5", 1}};
    // std::string str{R"(
    // {"+": [
    //         {
    //             "type": "FUNCTION",
    //             "id": "everMax",
    //             "args": [
    //                 {
    //                     "type": "VARIABLE",
    //                     "id": "amount_1"
    //                 },
    //                 {
    //                     "type": "VARIABLE",
    //                     "id": "amount_2"
    //                 }
    //             ]
    //         },
    //         {"-": [
    //             {"type": "VARIABLE", "id": "amount_3"},
    //             {"*": [
    //                 {"type": "VARIABLE", "id": "amount_4"},
    //                 {"type": "VARIABLE", "id": "amount_5"}
    //             ]}
    //         ]}
    //     ]}
    // )"};
    // json ast = json::parse(str);
    // int res = evaluate(ast, row);
    // std::cout << "Result: " << res << std::endl;

    // load ast from `sample_ast.json`
    std::cout << "Loading AST" << std::endl;
    std::ifstream i("sample_ast.json");
    json ast;
    i >> ast;
    std::cout << "AST Loaded " << ast << std::endl;

    // load rows from `large_data.json`
    std::cout << "Loading Rows" << std::endl;
    std::ifstream j("large_data.json");
    json rows;
    j >> rows;
    std::cout << "Rows Loaded" << std::endl;

    bulk_evaluate(ast, rows);
    return 0;
}