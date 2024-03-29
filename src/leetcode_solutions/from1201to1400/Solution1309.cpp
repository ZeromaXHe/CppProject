#include <iostream>

using namespace std;

/**
 * 1309. 解码字母到整数映射 | 难度：简单
 */
class Solution1309
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 43.83% 的用户
     * 通过测试用例：40 / 40
     */
    string freqAlphabets(string s)
    {
        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i + 2 < s.size() && s[i + 2] == '#')
            {
                res += char((s[i] - '0') * 10 + (s[i + 1] - '1') + 'a');
                i += 2;
            }
            else
            {
                res += char(s[i] - '1' + 'a');
            }
        }
        return res;
    }
};