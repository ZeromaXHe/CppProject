#include <iostream>

using namespace std;

/**
 * 1041. 困于环中的机器人 | 难度：中等
 */
class Solution1041
{
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 38.61% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 56.33% 的用户
     * 通过测试用例：116 / 116
     */
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0;
        int dirIdx = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (char c : instructions)
            {
                if (c == 'G')
                {
                    x += dir[dirIdx][0];
                    y += dir[dirIdx][1];
                }
                else if (c == 'R')
                {
                    dirIdx = (dirIdx + 1) % 4;
                }
                else
                {
                    dirIdx = (dirIdx + 3) % 4;
                }
            }
            if (x == 0 && y == 0 && dirIdx == 0)
                return true;
        }
        return false;
    }
};