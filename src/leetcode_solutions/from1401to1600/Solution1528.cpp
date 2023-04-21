#include <iostream>
#include <vector>

using namespace std;

/**
 * 1528. 重新排列字符串 | 难度：简单
 */
class Solution1528
{
public:
    /**
     * 其实可以直接用 string：
     * int length = s.length();
     * string result(length, 0);
     * 具体参考官方题解
     *
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 96.43% 的用户
     * 内存消耗：15 MB, 在所有 C++ 提交中击败了 16.56% 的用户
     * 通过测试用例：399 / 399
     */
    string restoreString(string s, vector<int> &indices)
    {
        vector<char> result(s.size());
        for (int i = 0; i < indices.size(); ++i)
        {
            result[indices[i]] = s[i];
        }
        result.emplace_back('\0');
        string str(result.data());
        return str;
    }
};