#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * 416. 分割等和子集 | 难度：中等
 */
class Solution416
{
public:
    /**
     * 官方题解
     *
     * 执行用时：256 ms, 在所有 C++ 提交中击败了 65.76% 的用户
     * 内存消耗：92.8 MB, 在所有 C++ 提交中击败了 8.37% 的用户
     * 通过测试用例：141 / 141
     */
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target)
        {
            return false;
        }
        // 其中 dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j。
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};