#include <vector>

using namespace std;

/**
 * 1800. 最大升序子数组和 | 难度：简单
 */
class Solution
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 39.83% 的用户
     * 内存消耗：8.1 MB, 在所有 C++ 提交中击败了 74.13% 的用户
     * 通过测试用例：104 / 104
     */
    int maxAscendingSum(vector<int> &nums)
    {
        int sum = 0;
        int res = 0;
        int pre = 0;
        for (int i : nums)
        {
            if (i > pre)
            {
                sum += i;
            }
            else
            {
                res = max(res, sum);
                sum = i;
            }
            pre = i;
        }
        return max(res, sum);
    }
};