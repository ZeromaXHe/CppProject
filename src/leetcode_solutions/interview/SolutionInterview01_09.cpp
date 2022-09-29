#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 面试题 01.09. 字符串轮转 | 难度：简单
 */
class Solution
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 77.35% 的用户
     * 内存消耗：7.6 MB, 在所有 C++ 提交中击败了 67.48% 的用户
     * 通过测试用例：31 / 31
     */
    bool isFlipedString(string s1, string s2)
    {
        return s1.length() == s2.length() && (s1 + s1).find(s2) != string::npos;
    }
};