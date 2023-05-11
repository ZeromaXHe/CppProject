#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * 1016. 子串能表示从 1 到 N 数字的二进制串 | 难度：中等
 */
class Solution1016
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 43.83% 的用户
     * 内存消耗：6.8 MB, 在所有 C++ 提交中击败了 6.17% 的用户
     * 通过测试用例：26 / 26
     */
    bool queryString(string s, int n)
    {
        unordered_set<int> set;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '0')
                continue;
            int j = i;
            int sum = 0;
            while (j < len && sum + s[j] - '0' <= n)
            {
                sum += s[j] - '0';
                set.emplace(sum);
                ++j;
                sum <<= 1;
            }
            if (set.size() == n)
                return true;
        }
        return set.size() == n;
    }
};