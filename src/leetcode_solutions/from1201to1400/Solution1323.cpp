#include <iostream>
#include <vector>

using namespace std;

/**
 * 1323. 6 和 9 组成的最大数字 | 难度：简单
 */
class Solution1323
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.7 MB, 在所有 C++ 提交中击败了 78.10% 的用户
     * 通过测试用例：153 / 153
     */
    int maximum69Number(int num)
    {
        int multi = 1;
        int test = num;
        int adder = 0;
        while (test > 0)
        {
            if (test % 10 == 6)
            {
                adder = 3 * multi;
            }
            multi *= 10;
            test /= 10;
        }
        return num + adder;
    }
};