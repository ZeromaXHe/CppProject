#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 2367. 算术三元组的数目 | 难度：简单
 */
class Solution2367
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 78.69% 的用户
     * 内存消耗：9 MB, 在所有 C++ 提交中击败了 5.10% 的用户
     * 通过测试用例：104 / 104
     */
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        unordered_set<int> set;
        unordered_set<int> afterDiffSet;
        int count = 0;
        for (int num : nums)
        {
            set.emplace(num);
            if (set.find(num - diff) != set.end())
                afterDiffSet.emplace(num);
            if (afterDiffSet.find(num - diff) != set.end())
                ++count;
        }
        return count;
    }
};
