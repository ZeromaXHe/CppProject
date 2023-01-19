#include <iostream>
#include <vector>

using namespace std;

/**
 * 1332. 删除回文子序列 | 难度：简单
 */
class Solution1332
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 59.64% 的用户
     * 通过测试用例：48 / 48
     * 
     * 参考题解做的。注意到只有 ab 和删除子序列可以不连续的话就不难，要不然就像我一样，以为题目很复杂。
     */
    int removePalindromeSub(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i)
        {
            if (s[i] != s[n - 1 - i])
            {
                return 2;
            }
        }
        return 1;
    }
};