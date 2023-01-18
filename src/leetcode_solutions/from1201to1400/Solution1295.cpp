#include <iostream>
#include <vector>

using namespace std;

/**
 * 1295. 统计位数为偶数的数字 | 难度：简单
 */
class Solution1295
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 50.38% 的用户
     * 内存消耗：9.4 MB, 在所有 C++ 提交中击败了 95.70% 的用户
     * 通过测试用例：105 / 105
     */
    int findNumbers(vector<int> &nums)
    {
        int result = 0;
        for (int num : nums)
        {
            // to_string(num).size() % 2 == 0
            if ((num >= 10 && num <= 99) || (num >= 1000 && num <= 9999) || num == 100000)
            {
                ++result;
            }
        }
        return result;
    }
};