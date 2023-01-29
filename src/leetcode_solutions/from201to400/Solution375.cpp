#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 375. 猜数字大小 II | 难度：中等
 */
class Solution375
{
public:
    /**
     * 参考题解做的，自己想动规没想出方向。感觉动规还是不熟。
     *
     * 执行用时：148 ms, 在所有 C++ 提交中击败了 61.30% 的用户
     * 内存消耗：7.9 MB, 在所有 C++ 提交中击败了 61.75% 的用户
     * 通过测试用例：27 / 27
     */
    int getMoneyAmount(int n)
    {
        // 不能用数组，数组不会给默认值 0
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 1; --i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                dp[i][j] = j + dp[i][j - 1];
                for (int k = i; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
