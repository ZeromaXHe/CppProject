#include <iostream>
#include <vector>

using namespace std;

/**
 * 2455. 可被三整除的偶数的平均值 | 难度：简单
 */
class Solution2455
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 34.11% 的用户
     * 内存消耗：13.4 MB, 在所有 C++ 提交中击败了 9.30% 的用户
     * 通过测试用例：181 / 181
     */
    int averageValue(vector<int> &nums)
    {
        int count = 0;
        int sum = 0;
        for (int num : nums)
        {
            if (num % 6 == 0)
            {
                sum += num;
                ++count;
            }
        }
        if (count == 0)
            return 0;
        return sum / count;
    }
};