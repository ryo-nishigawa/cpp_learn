#ifndef CPP_LEARN_LIB_HPP
#define CPP_LEARN_LIB_HPP

#include <string>
#include <vector>

namespace cpp_learn {

/**
 * @brief 計算機能を提供するクラス
 *
 * このクラスは基本的な数学的計算を行うためのユーティリティメソッドを提供します。
 */
class Calculator {
public:
    /**
     * @brief 二つの数値を加算する
     *
     * @param a 一つ目の数値
     * @param b 二つ目の数値
     * @return int 加算結果
     */
    static int add(int a, int b);

    /**
     * @brief 二つの数値を減算する
     *
     * @param a 一つ目の数値
     * @param b 二つ目の数値
     * @return int 減算結果
     */
    static int subtract(int a, int b);

    /**
     * @brief 二つの数値を乗算する
     *
     * @param a 一つ目の数値
     * @param b 二つ目の数値
     * @return int 乗算結果
     */
    static int multiply(int a, int b);

    /**
     * @brief 二つの数値を除算する
     *
     * @param a 一つ目の数値
     * @param b 二つ目の数値 (0ではないこと)
     * @return int 除算結果
     * @throw std::invalid_argument 除数が0の場合
     */
    static int divide(int a, int b);
};

/**
 * @brief 文字列操作機能を提供するクラス
 *
 * このクラスは文字列を操作するための便利なユーティリティメソッドを提供します。
 */
class StringUtils {
public:
    /**
     * @brief 文字列を逆順にする
     *
     * @param input 入力文字列
     * @return std::string 逆順にした文字列
     */
    static std::string reverse(const std::string& input);

    /**
     * @brief 文字列をトークンに分割する
     *
     * @param input 入力文字列
     * @param delimiter 区切り文字
     * @return std::vector<std::string> 分割されたトークン
     */
    static std::vector<std::string> split(const std::string& input, char delimiter);

    /**
     * @brief 文字列を結合する
     *
     * @param tokens 結合する文字列のベクター
     * @param delimiter 区切り文字
     * @return std::string 結合された文字列
     */
    static std::string join(const std::vector<std::string>& tokens, const std::string& delimiter);
};

}  // namespace cpp_learn

#endif  // CPP_LEARN_LIB_HPP