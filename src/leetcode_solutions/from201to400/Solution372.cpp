#include <iostream>
#include <vector>

using namespace std;

/**
 * 372. 超级次方 | 难度：中等
 */
class Solution372
{
    const int MOD = 1337;

    int pow(int x, int n)
    {
        int res = 1;
        while (n)
        {
            if (n % 2)
            {
                res = (long)res * x % MOD;
            }
            x = (long)x * x % MOD;
            n /= 2;
        }
        return res;
    }

public:
    /**
     * 数学题啊…… 参考官方题解做的
     *
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 98.18% 的用户
     * 内存消耗：11.3 MB, 在所有 C++ 提交中击败了 67.21% 的用户
     * 通过测试用例：55 / 55
     */
    int superPow(int a, vector<int> &b)
    {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; --i)
        {
            ans = (long)ans * pow(a, b[i]) % MOD;
            a = pow(a, 10);
        }
        return ans;
    }
};
