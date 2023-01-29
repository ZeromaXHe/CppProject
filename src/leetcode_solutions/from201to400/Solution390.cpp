#include <iostream>

using namespace std;

/**
 * 390. 消除游戏 | 难度：中等
 */
class Solution390
{
public:
    /**
     * 参考题解做的，这规律我自己是发现不了……
     * 
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 31.63% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 56.02% 的用户
     * 通过测试用例：3377 / 3377
     */
    int lastRemaining(int n)
    {
        int count = n;
        int round = 0;
        int head = 1;
        while (count > 1)
        {
            if (round % 2 == 0 || count % 2 == 1)
            {
                head += (1 << round);
            }
            ++round;
            count >>= 1;
        }
        return head;
    }
};
