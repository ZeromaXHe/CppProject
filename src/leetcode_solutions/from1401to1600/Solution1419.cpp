#include <iostream>

using namespace std;

/**
 * 1419. 数青蛙 | 难度：中等
 */
class Solution1419
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 95.78% 的用户
     * 内存消耗：9 MB, 在所有 C++ 提交中击败了 53.90% 的用户
     * 通过测试用例：60 / 60
     */
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int count[] = {0, 0, 0, 0};
        int maxCroaking = 0;
        int croaking = 0;
        for (char c : croakOfFrogs)
        {
            switch (c)
            {
            case 'c':
                ++count[0];
                ++croaking;
                if (croaking > maxCroaking)
                {
                    maxCroaking = croaking;
                }
                break;
            case 'r':
                if (count[0] > 0)
                {
                    --count[0];
                    ++count[1];
                }
                else
                {
                    return -1;
                }
                break;
            case 'o':
                if (count[1] > 0)
                {
                    --count[1];
                    ++count[2];
                }
                else
                {
                    return -1;
                }
                break;
            case 'a':
                if (count[2] > 0)
                {
                    --count[2];
                    ++count[3];
                }
                else
                {
                    return -1;
                }
                break;
            case 'k':
                if (count[3] > 0)
                {
                    --count[3];
                    --croaking;
                }
                else
                {
                    return -1;
                }
                break;
            default:
                return -1;
            }
        }
        if (croaking > 0)
        {
            return -1;
        }
        return maxCroaking;
    }
};