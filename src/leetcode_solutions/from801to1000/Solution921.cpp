#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 921. 使括号有效的最少添加 | 难度：中等
 */
class Solution921
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 62.32% 的用户
     * 通过测试用例：115 / 115
     */
    int minAddToMakeValid(string s)
    {
        int res = 0;
        int left = 0;
        for (char c : s)
        {
            if (c == '(')
                left++;
            else if (left > 0)
                left--;
            else
                res++;
        }
        return res + left;
    }
};