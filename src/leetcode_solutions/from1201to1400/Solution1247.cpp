#include <iostream>

using namespace std;

/**
 * 1247. 交换字符使得字符串相同 | 难度：中等
 */
class Solution1247
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 36.71% 的用户
     * 内存消耗：6.1 MB, 在所有 C++ 提交中击败了 44.94% 的用户
     * 通过测试用例：70 / 70
     */
    int minimumSwap(string s1, string s2)
    {
        int x1 = 0;
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
            {
                ++diff;
                if (s1[i] == 'x')
                    ++x1;
            }
        }
        if (diff % 2 == 1)
            return -1;
        return diff / 2 + (x1 % 2 == 0 ? 0 : 1);
    }
};
