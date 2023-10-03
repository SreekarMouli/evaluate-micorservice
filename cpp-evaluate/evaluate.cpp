#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int plus(int arg1, int arg2) {
    return arg1 + arg2;
}
int minus(int arg1, int arg2) {
    return arg1 - arg2;
}
int multiply(int arg1, int arg2) {
    return arg1 * arg2;
}
int handle_variable(const json& tok, const json& row) {
    std::string key = tok["id"];
    if (row.find(key) != row.end()) {
        return row[key];
    }
    return 0;
}
int evaluate(json& ast, json& row) {
    if (ast.is_object() && ast["type"] == "VARIABLE") {
        return handle_variable(ast, row);
    }
    std::string operator_str;
    operator_str = ast.begin().key();
    json& values = ast[operator_str];
    std::vector<int> evaluated_values;
    for (auto& val : values) {
        std::cout << "val: " << val << std::endl;
        evaluated_values.push_back(evaluate(val, row));
    }
    if (operator_str == "+") {
        return plus(evaluated_values[0], evaluated_values[1]);
    } else if (operator_str == "-") {
        return minus(evaluated_values[0], evaluated_values[1]);
    } else if (operator_str == "*") {
        return multiply(evaluated_values[0], evaluated_values[1]);
    }
    return 0;
}
int main() {
    json row = {
        {"id", "1"},
        {"email", "user1@mail.com"},
        {"sale_date", "2023-01-01"},
        {"amount_1", 100},
        {"amount_2", 80},
        {"amount_3", 5},
        {"amount_4", 6}
    };
    std::string str{ R"(
    {"+": [
            {"type": "VARIABLE", "id": "amount_1"},
            {"-": [
                {"type": "VARIABLE", "id": "amount_2"},
                {"*": [
                    {"type": "VARIABLE", "id": "amount_3"},
                    {"type": "VARIABLE", "id": "amount_4"}
                ]}
            ]}
        ]}
    )" };
    json ast = json::parse(str);
    int res = evaluate(ast, row);
    std::cout << "Result: " << res << std::endl;
    return 0;
}