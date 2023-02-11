#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 7. 整数反转 | 难度：中等
 */
class Solution7
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 6.72% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 45.95% 的用户
     * 通过测试用例：1032 / 1032
     */
    int reverse(int x)
    {
        if (x == INT32_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);
        int limit = INT32_MAX / 10;
        int res = 0;
        while (x >= 10)
        {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        if (res > limit || (res == limit && x > 7))
            return 0;
        return res * 10 + x;
    }
};
