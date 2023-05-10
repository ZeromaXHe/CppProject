#include <iostream>

using namespace std;

/**
 * 1015. 可被 K 整除的最小整数 | 难度：中等
 */
class Solution1015
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 59.85% 的用户
     * 通过测试用例：70 / 70
     */
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
        {
            return -1;
        }
        int i = 1;
        int mult = 10 % k;
        int remain = 1;
        while (remain % k != 0)
        {
            remain = remain % k + mult;
            mult = mult * 10 % k;
            ++i;
        }
        return i;
    }
};