#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 1784. 检查二进制字符串字段 | 难度：简单
 */
class Solution1784
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 49.61% 的用户
     * 通过测试用例：191 / 191
     */
    bool checkOnesSegment(string s)
    {
        int count = 0;
        char pre = '0';
        for (char ch : s)
        {
            if (ch != pre && ch == '1')
                count++;
            pre = ch;
        }
        return count <= 1;
    }
};