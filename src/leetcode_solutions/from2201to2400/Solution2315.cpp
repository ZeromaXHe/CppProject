#include <iostream>

using namespace std;

/**
 * 2315. 统计星号 | 难度：简单
 */
class Solution2315
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6.2 MB, 在所有 C++ 提交中击败了 81.59% 的用户
     * 通过测试用例：69 / 69
     */
    int countAsterisks(string s)
    {
        bool counting = true;
        int count = 0;
        for (char c : s)
        {
            if (c == '|')
            {
                counting = !counting;
            }
            else if (c == '*')
            {
                if (counting)
                    ++count;
            }
        }
        return count;
    }
};
