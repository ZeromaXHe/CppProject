#include <iostream>
#include <vector>

using namespace std;

/**
 * 1664. 生成平衡数组的方案数 | 难度：中等
 */
class Solution1664
{
public:
    /**
     * 执行用时：136 ms, 在所有 C++ 提交中击败了 12.50% 的用户
     * 内存消耗：113.2 MB, 在所有 C++ 提交中击败了 5.21% 的用户
     * 通过测试用例：105 / 105
     */
    int waysToMakeFair(vector<int> &nums)
    {
        vector<int> preOddSum = {0};
        vector<int> preEvenSum = {0};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i % 2 == 0)
            {
                preEvenSum.push_back(preEvenSum.back() + nums[i]);
                preOddSum.push_back(preOddSum.back());
            }
            else
            {
                preOddSum.push_back(preOddSum.back() + nums[i]);
                preEvenSum.push_back(preEvenSum.back());
            }
        }
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (preOddSum[i] + preEvenSum[nums.size()] - preEvenSum[i + 1] ==
                preEvenSum[i] + preOddSum[nums.size()] - preOddSum[i + 1])
            {
                ++count;
            }
        }
        return count;
    }

    /**
     * 执行用时：96 ms, 在所有 C++ 提交中击败了 83.33% 的用户
     * 内存消耗：93 MB, 在所有 C++ 提交中击败了 48.96% 的用户
     * 通过测试用例：105 / 105
     */
    int waysToMakeFair_arr(vector<int> &nums)
    {
        int len = nums.size();
        // cout << len << endl;
        int preOddSum[len + 1];
        int preEvenSum[len + 1];
        // 必须初始化，不然 C++ 这里是不会给默认值的，是内存里的随机值
        preOddSum[0] = 0;
        preEvenSum[0] = 0;
        for (int i = 0; i < len; ++i)
        {
            if (i % 2 == 0)
            {
                preEvenSum[i + 1] = preEvenSum[i] + nums[i];
                preOddSum[i + 1] = preOddSum[i];
            }
            else
            {
                preOddSum[i + 1] = preOddSum[i] + nums[i];
                preEvenSum[i + 1] = preEvenSum[i];
            }
        }
        // for (int i : preOddSum)
        // {
        //     cout << i << ' ';
        // }
        // cout << endl;
        // for (int i : preEvenSum)
        // {
        //     cout << i << ' ';
        // }
        // cout << endl;
        int count = 0;
        for (int i = 0; i < len; ++i)
        {
            if (preOddSum[i] + preEvenSum[len] - preEvenSum[i + 1] ==
                preEvenSum[i] + preOddSum[len] - preOddSum[i + 1])
            {
                ++count;
            }
        }
        return count;
    }
};
