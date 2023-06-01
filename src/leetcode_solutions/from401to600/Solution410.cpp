#include <iostream>
#include <vector>

using namespace std;

/**
 * 410. 分割数组的最大值 | 难度：困难
 */
class Solution410
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：7.1 MB, 在所有 C++ 提交中击败了 70.60% 的用户
     * 通过测试用例：31 / 31
     */
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int right = 0;
        int left = nums[0];
        for (int num : nums)
        {
            right += num;
            if (num > left)
                left = num;
        }
        int result = 0;
        while (right >= left)
        {
            int mid = (left + right) / 2;
            int sum = 0;
            int count = 1;
            for (int i = 0; i < n; ++i)
            {
                if (sum + nums[i] > mid)
                {
                    ++count;
                    sum = nums[i];
                }
                else
                {
                    sum += nums[i];
                }
            }
            if (count <= k)
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return result;
    }
};