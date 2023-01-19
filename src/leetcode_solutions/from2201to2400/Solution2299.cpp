#include <iostream>
#include <cctype>
#include <unordered_set>

using namespace std;

/**
 * 2299. 强密码检验器 II | 难度：简单
 */
class Solution2299
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6.2 MB, 在所有 C++ 提交中击败了 7.76% 的用户
     * 通过测试用例：148 / 148
     */
    bool strongPasswordCheckerII(string password)
    {
        if (password.size() < 8)
        {
            return false;
        }
        bool lower = false;
        bool upper = false;
        bool digit = false;
        bool special = false;
        unordered_set<char> specialSet = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        char pre = '?';
        for (char c : password)
        {
            if (pre == c)
            {
                return false;
            }
            pre = c;
            if (isdigit(c))
            {
                digit = true;
            }
            else if (isupper(c))
            {
                upper = true;
            }
            else if (islower(c))
            {
                lower = true;
            }
            // 貌似力扣上没有 contains 函数？
            else if (specialSet.count(c))
            {
                special = true;
            }
        }
        return digit & upper & lower & special;
    }
};