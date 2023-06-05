#include <iostream>
#include <vector>

using namespace std;

/**
 * 2460. 对数组执行操作 | 难度：简单
 */
class Solution2460
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 75.30% 的用户
     * 内存消耗：8.5 MB, 在所有 C++ 提交中击败了 97.21% 的用户
     * 通过测试用例：36 / 36
     */
    vector<int> applyOperations(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int firstZero = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                if (firstZero == -1)
                    firstZero = i;
            }
            else if (firstZero != -1)
            {
                nums[firstZero++] = nums[i];
                nums[i] = 0;
            }
        }
        return nums;
    }
};