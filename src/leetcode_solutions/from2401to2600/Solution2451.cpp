#include <iostream>
#include <vector>

using namespace std;

/**
 * 2451. 差值数组不同的字符串 | 难度：简单
 */
class Solution2451
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 59.09% 的用户
     * 内存消耗：7 MB, 在所有 C++ 提交中击败了 95.45% 的用户
     * 通过测试用例：39 / 39
     */
    string oddString(vector<string> &words)
    {
        vector<int> diff;
        int diffLine = -1;
        for (int j = 1; j < words[0].length(); ++j)
            diff.emplace_back(words[0][j] - words[0][j - 1]);
        for (int i = 1; i < words.size(); ++i)
        {
            string word = words[i];
            for (int j = 1; j < word.length(); ++j)
            {
                if (diff[j - 1] != word[j] - word[j - 1])
                {
                    if (diffLine != -1)
                        return words[0];
                    else
                    {
                        diffLine = i;
                        break;
                    }
                }
            }
        }
        return words[diffLine];
    }
};