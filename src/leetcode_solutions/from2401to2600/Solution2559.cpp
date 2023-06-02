#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 2559. 统计范围内的元音字符串数 | 难度：中等
 */
class Solution2559
{
public:
    /**
     * 执行用时：144 ms, 在所有 C++ 提交中击败了 26.65% 的用户
     * 内存消耗：67.6 MB, 在所有 C++ 提交中击败了 8.77% 的用户
     * 通过测试用例：93 / 93
     */
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> count{0};
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for (string word : words)
        {
            count.emplace_back(count[count.size() - 1] +
                               ((vowels.count(word[0]) && vowels.count(word[word.length() - 1])) ? 1 : 0));
        }
        vector<int> result;
        for (auto query : queries)
        {
            result.emplace_back(count[query[1] + 1] - count[query[0]]);
        }
        return result;
    }
};