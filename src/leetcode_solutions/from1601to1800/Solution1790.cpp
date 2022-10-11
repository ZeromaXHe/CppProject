#include <iostream>
#include <string>

using namespace std;

/**
 * 1790. 仅执行一次字符串交换能否使两个字符串相等 | 难度：简单
 */
class Solution1790
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 70.91% 的用户
     * 通过测试用例：131 / 131
     */
    bool areAlmostEqual(string s1, string s2)
    {
        char c1first = ' ';
        char c1second = ' ';
        char c2first = ' ';
        char c2second = ' ';
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
            {
                if (c1second != ' ')
                {
                    return false;
                }
                if (c1first == ' ')
                {
                    c1first = s1[i];
                    c2first = s2[i];
                }
                else
                {
                    c1second = s1[i];
                    c2second = s2[i];
                }
            }
        }
        return c1first == ' ' || (c1second != ' ' && c1first == c2second && c2first == c1second);
    }
};

int main(int argc, char *argv[])
{
    Solution1790 solution;
    std::cout << solution.areAlmostEqual("bank", "kanb") << std::endl;
    return 0;
}