#include <iostream>

using namespace std;

/**
 * 2437. 有效时间的数目 | 难度：简单
 */
class Solution2437
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 25.27% 的用户
     * 内存消耗：5.9 MB, 在所有 C++ 提交中击败了 17.44% 的用户
     * 通过测试用例：53 / 53
     */
    int countTime(string time)
    {
        int count1 = 1;
        if (time[0] == '?')
        {
            if (time[1] == '?')
                count1 = 24;
            else if (time[1] - '0' < 4)
                count1 = 3;
            else
                count1 = 2;
        }
        else if (time[1] == '?')
        {
            if (time[0] == '2')
                count1 = 4;
            else
                count1 = 10;
        }

        int count2 = 1;
        if (time[3] == '?')
        {
            if (time[4] == '?')
                count2 = 60;
            else
                count2 = 6;
        }
        else if (time[4] == '?')
        {
            count2 = 10;
        }

        return count1 * count2;
    }
};