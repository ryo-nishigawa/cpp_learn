#include <gtest/gtest.h>
#include <cpp_learn/lib.hpp>
#include <stdexcept>

// Calculator クラスのテスト
TEST(CalculatorTest, Addition) {
    // 正の数の加算をテスト
    EXPECT_EQ(5, cpp_learn::Calculator::add(2, 3));
    
    // 負の数の加算をテスト
    EXPECT_EQ(-1, cpp_learn::Calculator::add(2, -3));
    
    // ゼロの加算をテスト
    EXPECT_EQ(2, cpp_learn::Calculator::add(2, 0));
}

TEST(CalculatorTest, Subtraction) {
    // 正の結果の減算をテスト
    EXPECT_EQ(2, cpp_learn::Calculator::subtract(5, 3));
    
    // 負の結果の減算をテスト
    EXPECT_EQ(-1, cpp_learn::Calculator::subtract(2, 3));
    
    // ゼロを引くテスト
    EXPECT_EQ(5, cpp_learn::Calculator::subtract(5, 0));
}

TEST(CalculatorTest, Multiplication) {
    // 正の数の乗算をテスト
    EXPECT_EQ(6, cpp_learn::Calculator::multiply(2, 3));
    
    // 負の数を含む乗算をテスト
    EXPECT_EQ(-6, cpp_learn::Calculator::multiply(2, -3));
    
    // ゼロとの乗算をテスト
    EXPECT_EQ(0, cpp_learn::Calculator::multiply(5, 0));
}

TEST(CalculatorTest, Division) {
    // 正の数の除算をテスト
    EXPECT_EQ(2, cpp_learn::Calculator::divide(6, 3));
    
    // 負の数を含む除算をテスト
    EXPECT_EQ(-2, cpp_learn::Calculator::divide(6, -3));
    
    // 割り切れない除算をテスト
    EXPECT_EQ(2, cpp_learn::Calculator::divide(5, 2)); // 整数除算なので2になる
    
    // ゼロによる除算は例外をスローすることをテスト
    EXPECT_THROW(cpp_learn::Calculator::divide(5, 0), std::invalid_argument);
}

// StringUtils クラスのテスト
TEST(StringUtilsTest, Reverse) {
    // 通常の文字列の反転をテスト
    EXPECT_EQ("cba", cpp_learn::StringUtils::reverse("abc"));
    
    // 空文字列の反転をテスト
    EXPECT_EQ("", cpp_learn::StringUtils::reverse(""));
    
    // 単一文字の反転をテスト
    EXPECT_EQ("a", cpp_learn::StringUtils::reverse("a"));
    
    // パリンドローム（回文）の反転をテスト
    EXPECT_EQ("level", cpp_learn::StringUtils::reverse("level"));
}

TEST(StringUtilsTest, Split) {
    // カンマで分割するテスト
    std::vector<std::string> expected1 = {"apple", "banana", "cherry"};
    EXPECT_EQ(expected1, cpp_learn::StringUtils::split("apple,banana,cherry", ','));
    
    // 空文字列の分割をテスト
    std::vector<std::string> expected2 = {""};
    EXPECT_EQ(expected2, cpp_learn::StringUtils::split("", ','));
    
    // 区切り文字を含まない文字列の分割をテスト
    std::vector<std::string> expected3 = {"apple"};
    EXPECT_EQ(expected3, cpp_learn::StringUtils::split("apple", ','));
    
    // 連続した区切り文字を含む文字列の分割をテスト
    std::vector<std::string> expected4 = {"apple", "", "banana"};
    EXPECT_EQ(expected4, cpp_learn::StringUtils::split("apple,,banana", ','));
}

TEST(StringUtilsTest, Join) {
    // 通常の結合をテスト
    std::vector<std::string> tokens1 = {"apple", "banana", "cherry"};
    EXPECT_EQ("apple,banana,cherry", cpp_learn::StringUtils::join(tokens1, ","));
    
    // 空のベクターの結合をテスト
    std::vector<std::string> tokens2 = {};
    EXPECT_EQ("", cpp_learn::StringUtils::join(tokens2, ","));
    
    // 単一要素の結合をテスト
    std::vector<std::string> tokens3 = {"apple"};
    EXPECT_EQ("apple", cpp_learn::StringUtils::join(tokens3, ","));
    
    // 異なる区切り文字での結合をテスト
    EXPECT_EQ("apple-banana-cherry", cpp_learn::StringUtils::join(tokens1, "-"));
}