#include <iostream>
#include <vector>

using namespace std;

/**
 * 2517. 礼盒的最大甜蜜度 | 难度：中等
 */
class Solution2517
{
public:
    /**
     * 执行用时：208 ms, 在所有 C++ 提交中击败了 37.80% 的用户
     * 内存消耗：47.3 MB, 在所有 C++ 提交中击败了 47.32% 的用户
     * 通过测试用例：40 / 40
     */
    int maximumTastiness(vector<int> &price, int k)
    {
        int n = price.size();
        sort(price.begin(), price.end());
        int right = price[n - 1] - price[0];
        int left = 0;
        int result = 0;
        while (right >= left)
        {
            int mid = (left + right) / 2;
            int count = 1;
            int pre = 0;
            for (int i = 1; i < n; ++i)
            {
                if (price[i] - price[pre] >= mid)
                {
                    ++count;
                    pre = i;
                }
            }
            if (count >= k)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }

    /**
     * 超时
     */
    int maximumTastiness_timeout(vector<int> &price, int k)
    {
        int n = price.size();
        vector<vector<int>> dp(k, vector<int>(n, 0));
        sort(price.begin(), price.end());
        int result = 0;
        // i = 组数量 - 1
        for (int i = 1; i < k; ++i)
        {
            // j = 选取的最后一个价格索引
            for (int j = 1; j < n; ++j)
            {
                // m = 选取的前一个价格索引
                for (int m = i - 1; m < j; ++m)
                {
                    dp[i][j] = max(dp[i][j], min(price[j] - price[m], i == 1 ? INT32_MAX : dp[i - 1][m]));
                    if (i == k - 1)
                        result = max(dp[i][j], result);
                }
            }
        }
        return result;
    }
};