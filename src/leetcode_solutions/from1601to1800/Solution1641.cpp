#include <iostream>

using namespace std;

/**
 * 1641. 统计字典序元音字符串的数目 | 难度：中等
 */
class Solution1641
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 69.36% 的用户
     * 通过测试用例：41 / 41
     */
    int countVowelStrings(int n)
    {
        int dp[5]{1, 1, 1, 1, 1};
        int preSum[5]{1, 2, 3, 4, 5};
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < 5; ++j)
            {
                dp[j] += preSum[j - 1];
            }
            preSum[0] = dp[0];
            for (int j = 1; j < 5; ++j)
            {
                preSum[j] = preSum[j - 1] + dp[j];
            }
        }
        return preSum[4];
    }
};
