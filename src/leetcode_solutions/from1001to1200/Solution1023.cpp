#include <iostream>
#include <vector>

using namespace std;

/**
 * 1023. 驼峰式匹配 | 难度：中等
 */
class Solution1023
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 45.38% 的用户
     * 内存消耗：6.8 MB, 在所有 C++ 提交中击败了 92.31% 的用户
     * 通过测试用例：36 / 36
     */
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> result;
        for (string query : queries)
        {
            int pIdx = 0;
            bool match = true;
            for (int i = 0; i < query.length(); ++i)
            {
                if (pIdx < pattern.length() && query[i] == pattern[pIdx])
                    ++pIdx;
                else if (isupper(query[i]))
                {
                    match = false;
                    break;
                }
            }
            if (pIdx < pattern.length())
                match = false;
            result.emplace_back(match);
        }
        return result;
    }
};