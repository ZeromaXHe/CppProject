#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 2341. 数组能形成多少数对 | 难度：简单
 */
class Solution2341
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 60.46% 的用户
     * 内存消耗：9 MB, 在所有 C++ 提交中击败了 38.40% 的用户
     * 通过测试用例：128 / 128
     */
    vector<int> numberOfPairs(vector<int> &nums)
    {
        int pair = 0;
        unordered_set<int> set;
        for (int num : nums)
        {
            if (set.find(num) != set.end())
            {
                set.erase(num);
                ++pair;
            }
            else
            {
                set.emplace(num);
            }
        }
        return vector<int>{pair, (int)set.size()};
    }
};
