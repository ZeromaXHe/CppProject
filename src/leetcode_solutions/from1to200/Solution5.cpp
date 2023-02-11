#include <iostream>
#include <vector>

using namespace std;

/**
 * 5. 最长回文子串 | 难度：中等
 */
class Solution5
{
public:
    /**
     * 执行用时：140 ms, 在所有 C++ 提交中击败了 47.84% 的用户
     * 内存消耗：22 MB, 在所有 C++ 提交中击败了 50.95% 的用户
     * 通过测试用例：141 / 141
     */
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }
        int max = 1;
        int maxFrom = 0;
        for (int span = 1; span < n; ++span)
        {
            for (int from = 0; from < n - span; ++from)
            {
                if (s[from] == s[from + span] && (span == 1 || dp[from + 1][from + span - 1]))
                {
                    dp[from][from + span] = true;
                    if (span + 1 > max)
                    {
                        max = span + 1;
                        maxFrom = from;
                    }
                }
            }
        }
        return s.substr(maxFrom, max);
    }
};
