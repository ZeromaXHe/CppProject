#include <iostream>
#include <vector>

using namespace std;

/**
 * 1480. 一维数组的动态和 | 难度：简单
 */
class Solution1480
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：8.3 MB, 在所有 C++ 提交中击败了 32.91% 的用户
     * 通过测试用例：53 / 53
     */
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> result = {nums[0]};
        for (int i = 1; i < nums.size(); ++i)
            result.emplace_back(result[i - 1] + nums[i]);
        return result;
    }
};