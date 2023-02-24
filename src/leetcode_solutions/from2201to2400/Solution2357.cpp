#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 2357. 使数组中所有元素都等于零 | 难度：简单
 */
class Solution2357
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：8.2 MB, 在所有 C++ 提交中击败了 33.43% 的用户
     * 通过测试用例：95 / 95
     */
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int num : nums)
        {
            set.emplace(num);
        }
        return set.find(0) != set.end() ? set.size() - 1 : set.size();
    }
};
