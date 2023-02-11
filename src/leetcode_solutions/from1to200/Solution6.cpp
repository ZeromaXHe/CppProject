#include <iostream>

using namespace std;

/**
 * 6. N 字形变换 | 难度：中等
 */
class Solution6
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 80.16% 的用户
     * 内存消耗：8.1 MB, 在所有 C++ 提交中击败了 74.19% 的用户
     * 通过测试用例：1157 / 1157
     */
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string result;
        int circulation = 2 * numRows - 2;
        for (int i = 0; i < s.size(); i += circulation)
            result += s[i];
        for (int i = 1; i < numRows - 1; ++i)
        {
            // 少了这个判断的话，输入 "A" 4 会报错
            if (i >= s.size())
                break;
            for (int j = 0; j < s.size() - i; j += circulation)
            {
                result += s[i + j];
                if (j + circulation - i < s.size())
                    result += s[j + circulation - i];
            }
        }
        for (int i = numRows - 1; i < s.size(); i += circulation)
            result += s[i];
        return result;
    }
};
