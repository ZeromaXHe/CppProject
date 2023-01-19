#include <iostream>
#include <vector>

using namespace std;

/**
 * 1313. 解压缩编码列表 | 难度：简单
 */
class Solution1313
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 3.02% 的用户
     * 内存消耗：9.9 MB, 在所有 C++ 提交中击败了 8.30% 的用户
     * 通过测试用例：53 / 53
     */
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i += 2)
        {
            for (int j = 0; j < nums[i]; ++j)
            {
                result.push_back(nums[i + 1]);
            }
        }
        return result;
    }
};