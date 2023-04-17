#include <iostream>
#include <vector>

using namespace std;

/**
 * 1431. 拥有最多糖果的孩子 | 难度：简单
 */
class Solution1431
{
public:
    /**
     * 官方题解
     *
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 13.57% 的用户
     * 内存消耗：8.7 MB, 在所有 C++ 提交中击败了 39.46% 的用户
     * 通过测试用例：103 / 103
     */
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> ret;
        for (int i = 0; i < n; ++i)
        {
            ret.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return ret;
    }
};