#include <iostream>

using namespace std;

/**
 * 1342. 将数字变成 0 的操作次数 | 难度：简单
 */
class Solution1342
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 32.28% 的用户
     * 通过测试用例：204 / 204
     */
    int numberOfSteps(int num)
    {
        int step = 0;
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                --num;
            }
            ++step;
        }
        return step;
    }
};
