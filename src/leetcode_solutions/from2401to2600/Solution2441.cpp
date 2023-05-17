#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 2441. 与对应负数同时存在的最大正整数 | 难度：简单
 */
class Solution2441
{
public:
    /**
     * 执行用时：32 ms, 在所有 C++ 提交中击败了 33.03% 的用户
     * 内存消耗：24.1 MB, 在所有 C++ 提交中击败了 5.15% 的用户
     * 通过测试用例：337 / 337
     */
    int findMaxK(vector<int> &nums)
    {
        unordered_set<int> set;
        int result = -1;
        for (int num : nums)
        {
            if (set.find(-num) != set.end())
            {
                result = max(result, ::abs(num));
            }
            set.emplace(num);
        }
        return result;
    }
};