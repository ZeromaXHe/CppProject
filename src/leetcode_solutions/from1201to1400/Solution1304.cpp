#include <iostream>
#include <vector>

using namespace std;

/**
 * 1304. 和为零的 N 个不同整数 | 难度：简单
 */
class Solution1304
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6.7 MB, 在所有 C++ 提交中击败了 9.47% 的用户
     * 通过测试用例：42 / 42
     */
    vector<int> sumZero(int n)
    {
        vector<int> result;
        int count = n / 2;
        if (n % 2 == 1)
        {
            result.push_back(0);
        }
        for (int i = 1; i <= count; ++i)
        {
            result.push_back(i);
            result.push_back(-i);
        }
        return result;
    }
};