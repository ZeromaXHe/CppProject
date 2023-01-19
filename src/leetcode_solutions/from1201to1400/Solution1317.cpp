#include <iostream>
#include <vector>

using namespace std;

/**
 * 1317. 将整数转换为两个无零整数的和 | 难度：简单
 */
class Solution1317
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 41.33% 的用户
     * 内存消耗：6.2 MB, 在所有 C++ 提交中击败了 33.67% 的用户
     * 通过测试用例：207 / 207
     */
    vector<int> getNoZeroIntegers(int n)
    {
        for (int a = 1; a < n; ++a)
        {
            int b = n - a;
            if ((to_string(a) + to_string(b)).find('0') == string::npos)
            {
                return {a, b};
            }
        }
        return {};
    }
};