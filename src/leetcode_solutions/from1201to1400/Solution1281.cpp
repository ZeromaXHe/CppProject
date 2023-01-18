#include <iostream>

using namespace std;

/**
 * 1281. 整数的各位积和之差 | 难度：简单
 */
class Solution1281
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 25.29% 的用户
     * 通过测试用例：123 / 123
     */
    int subtractProductAndSum(int n)
    {
        int sum = 0;
        int prod = 1;
        while (n > 0)
        {
            sum += n % 10;
            prod *= n % 10;
            n /= 10;
        }
        return prod - sum;
    }
};