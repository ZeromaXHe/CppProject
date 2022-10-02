#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 777. 在LR字符串中交换相邻字符 | 难度：中等
 */
class Solution
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 93.72% 的用户
     * 内存消耗：7.2 MB, 在所有 C++ 提交中击败了 62.34% 的用户
     * 通过测试用例：94 / 94
     */
    bool canTransform(string start, string end)
    {
        int i = 0;
        int r = 0;
        int l = 0;
        while (i < start.length())
        {
            if (start[i] == 'R')
            {
                if (end[i] == 'L')
                    return false;
                else if (end[i] == 'X')
                {
                    if (l > 0)
                        return false;
                    r++;
                }
                else if (l > 0)
                    return false;
            }
            else if (start[i] == 'L')
            {
                if (end[i] == 'R')
                {
                    if (r <= 0)
                        return false;
                    r--;
                    l++;
                }
                else if (end[i] == 'X')
                {
                    if (l <= 0)
                        return false;
                    else
                        l--;
                }
                else if (r > 0)
                    return false;
            }
            else
            {
                if (end[i] == 'L')
                    l++;
                else if (end[i] == 'R')
                {
                    if (r <= 0)
                        return false;
                    else
                        r--;
                }
            }
            i++;
        }
        return l == 0 && r == 0;
    }
};