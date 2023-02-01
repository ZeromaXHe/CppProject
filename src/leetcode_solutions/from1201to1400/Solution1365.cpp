#include <iostream>
#include <vector>

using namespace std;

/**
 * 1365. 有多少小于当前数字的数字 | 难度：简单
 */
class Solution1365
{
public:
    /**
     * 官方题解答案
     *
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 60.20% 的用户
     * 内存消耗：10.2 MB, 在所有 C++ 提交中击败了 14.52% 的用户
     * 通过测试用例：103 / 103
     */
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<pair<int, int>> data;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // emplace_back 效率比 push_back 高，C++ 11 中增加
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());

        vector<int> ret(n, 0);
        int prev = -1;
        for (int i = 0; i < n; i++)
        {
            if (prev == -1 || data[i].first != data[i - 1].first)
            {
                prev = i;
            }
            ret[data[i].second] = prev;
        }
        return ret;
    }
};
