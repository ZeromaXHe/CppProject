#include <iostream>

using namespace std;

/**
 * 1017. 负二进制转换 | 难度：中等
 */
class Solution1017
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 10.18% 的用户
     * 通过测试用例：170 / 170
     */
    string baseNeg2(int n)
    {
        string ans;
        while (n)
        {
            int remain = n % (-2);
            ans += '0' + ::abs(remain);
            // 负二进制的余数可能有 0，1，-1，而表示上不能有负数，所以在余数为 -1 时，要转化为 1，同时商 +1 即可
            n = remain < 0 ? n / (-2) + 1 : n / (-2);
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};