#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1512. 好数对的数目 | 难度：简单
 */
class Solution1512
{
public:
    /**
     * 官方题解
     *
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：7 MB, 在所有 C++ 提交中击败了 65.55% 的用户
     * 通过测试用例：48 / 48
     */
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];

        int ans = 0;
        for (const auto &[k, v] : m)
            ans += v * (v - 1) / 2;

        return ans;
    }
};
