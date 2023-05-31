#include <iostream>
#include <vector>

using namespace std;

/**
 * 1130. 叶值的最小代价生成树 | 难度：中等
 */
class Solution1130
{
public:
    /**
     * 官方题解，感觉自己就没仔细读懂题目…… 看了题解才反应过来非叶节点的值是计算的左右子树里面各自叶节点最大值的乘积
     *
     * 执行用时：16 ms, 在所有 C++ 提交中击败了 34.42% 的用户
     * 内存消耗：9 MB, 在所有 C++ 提交中击败了 26.51% 的用户
     * 通过测试用例：103 / 103
     */
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        // 使用 dp[i][j] 表示子数组 [i,j] (i≤j) 对应的子树所有非叶子节点的最小总和
        // 其中 mval[i][k] ​表示子数组 [i,k] 的最大值
        vector<vector<int>> dp(n, vector<int>(n, INT32_MAX / 4)), mval(n, vector<int>(n));
        for (int j = 0; j < n; j++)
        {
            mval[j][j] = arr[j];
            dp[j][j] = 0;
            for (int i = j - 1; i >= 0; i--)
            {
                mval[i][j] = max(arr[i], mval[i + 1][j]);
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};