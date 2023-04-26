#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * 1031. 两个非重叠子数组的最大和 | 难度：中等
 */
class Solution1031
{
public:
    /**
     * 官方题解把空间复杂度压到 O(1) 了，有空看看
     * 
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 86.90% 的用户
     * 内存消耗：8.1 MB, 在所有 C++ 提交中击败了 92.58% 的用户
     * 通过测试用例：51 / 51
     */
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        return max(maxSum(nums, firstLen, secondLen), maxSum(nums, secondLen, firstLen));
    }

    int maxSum(vector<int> &nums, int firstLen, int secondLen)
    {
        int n = nums.size();
        int m = n - firstLen - secondLen;
        if (m == 0)
        {
            return accumulate(nums.begin(), nums.end(), 0);
        }
        int dp1[m + 1];
        int dp2[m + 1];
        int sum = 0;
        for (int i = 0; i < firstLen; ++i)
        {
            sum += nums[i];
        }
        dp1[0] = sum;
        for (int i = 0; i < m; ++i)
        {
            sum += nums[i + firstLen] - nums[i];
            dp1[i + 1] = max(dp1[i], sum);
        }
        sum = 0;
        for (int i = 0; i < secondLen; ++i)
        {
            sum += nums[n - 1 - i];
        }
        dp2[m] = sum;
        for (int i = 0; i < m; ++i)
        {
            sum += nums[n - 1 - secondLen - i] - nums[n - 1 - i];
            dp2[m - 1 - i] = max(sum, dp2[m - i]);
        }
        int maxi = 0;
        for (int i = 0; i <= m; ++i)
        {
            maxi = max(maxi, dp1[i] + dp2[i]);
        }
        return maxi;
    }
};