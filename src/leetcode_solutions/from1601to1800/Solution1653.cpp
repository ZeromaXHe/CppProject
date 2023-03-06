#include <iostream>
#include <vector>

using namespace std;

/**
 * 1653. 使字符串平衡的最少删除次数 | 难度：中等
 */
class Solution1653
{
public:
    /**
     * 执行用时：108 ms, 在所有 C++ 提交中击败了 32.35% 的用户
     * 内存消耗：50.2 MB, 在所有 C++ 提交中击败了 20.59% 的用户
     * 通过测试用例：157 / 157
     */
    int minimumDeletions(string s)
    {
        vector<int> preB(s.length() + 1);
        vector<int> posA(s.length() + 1);
        for (int i = 0; i < s.length(); ++i)
        {
            preB[i + 1] = preB[i] + (s[i] == 'b' ? 1 : 0);
        }
        for (int i = s.length() - 1; i >= 0; --i)
        {
            posA[i] = posA[i + 1] + (s[i] == 'a' ? 1 : 0);
        }
        int min = s.length();
        for (int i = 0; i <= s.length(); ++i)
        {
            if (preB[i] + posA[i] < min)
                min = preB[i] + posA[i];
        }
        return min;
    }
};
