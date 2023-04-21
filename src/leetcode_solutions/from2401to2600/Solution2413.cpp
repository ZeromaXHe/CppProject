#include <iostream>
#include <vector>

using namespace std;

/**
 * 2413. 最小偶倍数 | 难度：简单
 */
class Solution2413
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.7 MB, 在所有 C++ 提交中击败了 89.33% 的用户
     * 通过测试用例：150 / 150
     */
    int smallestEvenMultiple(int n)
    {
        if (n % 2 == 0)
            return n;
        else
            return n * 2;
    }
};