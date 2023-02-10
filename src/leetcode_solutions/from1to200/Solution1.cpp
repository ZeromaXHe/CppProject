#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1. 两数之和 | 难度：简单
 */
class Solution1
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 67.63% 的用户
     * 内存消耗：10.5 MB, 在所有 C++ 提交中击败了 36.22% 的用户
     * 通过测试用例：57 / 57
     */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.count(target - nums[i]))
            {
                return vector<int>{map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }
        return vector<int>{};
    }
};
