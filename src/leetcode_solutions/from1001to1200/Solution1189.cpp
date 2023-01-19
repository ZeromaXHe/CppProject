#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 1189. “气球” 的最大数量 | 难度：简单
 */
class Solution1189
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 66.57% 的用户
     * 内存消耗：6.5 MB, 在所有 C++ 提交中击败了 13.56% 的用户
     * 通过测试用例：25 / 25
     */
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> count;
        for (char c : text)
        {
            ++count[c];
        }
        int result = count['b'];
        if (result == 0)
            return result;
        if (count['a'] < result)
        {
            result = count['a'];
            if (result == 0)
                return result;
        }
        if (count['l'] / 2 < result)
        {
            result = count['l'] / 2;
            if (result == 0)
                return result;
        }
        if (count['o'] / 2 < result)
        {
            result = count['o'] / 2;
            if (result == 0)
                return result;
        }
        if (count['n'] < result)
        {
            result = count['n'];
            if (result == 0)
                return result;
        }
        return result;
    }
};