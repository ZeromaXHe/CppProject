#include <iostream>
#include <vector>

using namespace std;

/**
 * 1043. 分隔数组以得到最大和 | 难度：中等
 */
class Solution1043
{
public:
    /**
     * 执行用时：20 ms, 在所有 C++ 提交中击败了 31.60% 的用户
     * 内存消耗：8.3 MB, 在所有 C++ 提交中击败了 31.60% 的用户
     * 通过测试用例：52 / 52
     */
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int maxV = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; --j)
            {
                maxV = max(maxV, arr[j]);
                dp[i] = max(dp[i], dp[j] + maxV * (i - j));
            }
        }
        return dp[n];
    }
};