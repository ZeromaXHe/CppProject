#include <iostream>
#include <vector>

using namespace std;

/**
 * 1389. 按既定顺序创建目标数组 | 难度：简单
 */
class Solution1389
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：8.1 MB, 在所有 C++ 提交中击败了 78.95% 的用户
     * 通过测试用例：45 / 45
     */
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            result.insert(result.begin() + index[i], nums[i]);
        }
        return result;
    }
};
