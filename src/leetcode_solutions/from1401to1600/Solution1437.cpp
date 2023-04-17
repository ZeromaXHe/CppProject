#include <iostream>
#include <vector>

using namespace std;

/**
 * 1437. 是否所有 1 都至少相隔 k 个元素 | 难度：简单
 */
class Solution1437
{
public:
    /**
     * 执行用时：40 ms, 在所有 C++ 提交中击败了 97.71% 的用户
     * 内存消耗：56.1 MB, 在所有 C++ 提交中击败了 90.83% 的用户
     * 通过测试用例：68 / 68
     */
    bool kLengthApart(vector<int> &nums, int k)
    {
        int count = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i])
            {
                if (count >= 0 && count < k)
                    return false;
                count = 0;
            }
            else if (count >= 0)
                ++count;
        }
        return true;
    }
};