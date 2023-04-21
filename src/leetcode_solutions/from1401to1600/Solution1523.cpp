#include <iostream>

using namespace std;

/**
 * 1523. 在区间范围内统计奇数数目 | 难度：简单
 */
class Solution1523
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.9 MB, 在所有 C++ 提交中击败了 5.20% 的用户
     * 通过测试用例：84 / 84
     */
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - low / 2;
    }
};