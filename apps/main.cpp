#include <cpp_learn/lib.hpp>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "C++ サンプルアプリケーション" << std::endl;
    std::cout << "==========================" << std::endl;

    // Calculator クラスのデモ
    std::cout << "\n[Calculator デモ]" << std::endl;
    std::cout << "2 + 3 = " << cpp_learn::Calculator::add(2, 3) << std::endl;
    std::cout << "5 - 3 = " << cpp_learn::Calculator::subtract(5, 3) << std::endl;
    std::cout << "2 * 3 = " << cpp_learn::Calculator::multiply(2, 3) << std::endl;

    try {
        std::cout << "6 / 3 = " << cpp_learn::Calculator::divide(6, 3) << std::endl;
        std::cout << "5 / 0 = ";
        std::cout << cpp_learn::Calculator::divide(5, 0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "例外が発生しました: " << e.what() << std::endl;
    }

    // StringUtils クラスのデモ
    std::cout << "\n[StringUtils デモ]" << std::endl;

    std::string original = "Hello, World!";
    std::cout << "元の文字列: " << original << std::endl;
    std::cout << "反転した文字列: " << cpp_learn::StringUtils::reverse(original) << std::endl;

    std::string csv = "apple,banana,cherry,date";
    std::cout << "\n元のCSV: " << csv << std::endl;
    std::vector<std::string> fruits = cpp_learn::StringUtils::split(csv, ',');

    std::cout << "分割した結果:" << std::endl;
    for (const auto& fruit : fruits) {
        std::cout << "  - " << fruit << std::endl;
    }

    std::string joined = cpp_learn::StringUtils::join(fruits, " | ");
    std::cout << "\n異なる区切り文字で結合: " << joined << std::endl;

    std::cout << "\nプログラムを終了します。" << std::endl;
    return 0;
}