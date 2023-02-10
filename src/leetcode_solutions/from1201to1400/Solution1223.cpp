#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1223. 掷骰子模拟 | 难度：困难
 */
class Solution1223
{
    static const int mod = 1E9 + 7;

public:
    /**
     * 执行用时：196 ms, 在所有 C++ 提交中击败了 16.30% 的用户
     * 内存消耗：29.6 MB, 在所有 C++ 提交中击败了 27.17% 的用户
     * 通过测试用例：32 / 32
     */
    int dieSimulator(int n, vector<int> &rollMax)
    {
        vector dp(n + 1, vector(6, vector<int>(16)));
        for (int i = 0; i < 6; ++i)
            dp[1][i][1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                for (int k = 1; k <= rollMax[j]; ++k)
                {
                    for (int m = 0; m < 6; ++m)
                    {
                        if (m != j)
                            dp[i][m][1] = (dp[i][m][1] + dp[i - 1][j][k]) % mod;
                        else if (k < rollMax[j])
                            dp[i][m][k + 1] = (dp[i][m][k + 1] + dp[i - 1][j][k]) % mod;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 1; j <= rollMax[i]; ++j)
            {
                res = (res + dp[n][i][j]) % mod;
            }
        }
        return res;
    }
};
