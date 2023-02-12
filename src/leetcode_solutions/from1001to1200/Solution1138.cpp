#include <iostream>
#include <vector>

using namespace std;

/**
 * 1138. 字母板上的路径 | 难度：中等
 */
class Solution1138
{
    string fromC1toTypeC2(char c1, char c2)
    {
        int x1 = (c1 - 'a') / 5;
        int y1 = (c1 - 'a') % 5;
        int x2 = (c2 - 'a') / 5;
        int y2 = (c2 - 'a') % 5;
        string res;
        if (c1 != 'z')
        {
            if (y1 < y2)
            {
                for (int i = y1; i < y2; ++i)
                {
                    res += 'R';
                }
            }
            else if (y1 > y2)
            {
                for (int i = y1; i > y2; --i)
                {
                    res += 'L';
                }
            }
        }

        if (x1 < x2)
        {
            for (int i = x1; i < x2; ++i)
            {
                res += 'D';
            }
        }
        else if (x1 > x2)
        {
            for (int i = x1; i > x2; --i)
            {
                res += 'U';
            }
        }

        if (c1 == 'z' && y1 < y2)
        {
            for (int i = y1; i < y2; ++i)
            {
                res += 'R';
            }
        }

        res += '!';
        return res;
    }

public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.9 MB, 在所有 C++ 提交中击败了 68.69% 的用户
     * 通过测试用例：61 / 61
     */
    string alphabetBoardPath(string target)
    {
        char from = 'a';
        string res;
        for (char to : target)
        {
            res += fromC1toTypeC2(from, to);
            from = to;
        }
        return res;
    }
};
