#include <algorithm>
#include <cpp_learn/lib.hpp>
#include <sstream>
#include <stdexcept>

namespace cpp_learn {

// Calculator クラスの実装
int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}

int Calculator::divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("除数がゼロです");
    }
    return a / b;
}

// StringUtils クラスの実装
std::string StringUtils::reverse(const std::string& input) {
    std::string reversed = input;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

std::vector<std::string> StringUtils::split(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = 0;
    
    while ((end = input.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + 1;
    }
    
    // 最後のトークンを追加（または入力文字列に区切り文字がない場合）
    tokens.push_back(input.substr(start));
    
    return tokens;
}

std::string StringUtils::join(const std::vector<std::string>& tokens,
                              const std::string& delimiter) {
    if (tokens.empty()) {
        return "";
    }

    std::ostringstream result;
    result << tokens[0];

    for (size_t i = 1; i < tokens.size(); ++i) {
        result << delimiter << tokens[i];
    }

    return result.str();
}

}  // namespace cpp_learn