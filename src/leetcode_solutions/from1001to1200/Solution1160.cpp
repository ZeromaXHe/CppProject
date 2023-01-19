#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 1160. 拼写单词 | 难度：简单
 */
class Solution1160
{
public:
    /**
     * 执行用时：200 ms, 在所有 C++ 提交中击败了 14.45% 的用户
     * 内存消耗：50.2 MB, 在所有 C++ 提交中击败了 34.34% 的用户
     * 通过测试用例：36 / 36
     * 
     * 为啥这么慢…… 看用 vector 实现的话效率高些
     */
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> count;
        for (char c : chars)
        {
            ++count[c];
        }
        int result = 0;
        for (string word : words)
        {
            unordered_map<char, int> count2;
            for (char c2 : word)
            {
                ++count2[c2];
            }
            bool comprehend = true;
            for (auto &entry : count2)
            {
                // 力扣里面貌似没有 contains 函数,可以用 count 代替，因为 C++ 0 以外的值等于 true，0 等同于 false
                // 但这里因为直接访问时，如果 key 不存在，访问仍然成功，取得 value 对象默认构造的值（即 9），所以可以直接写
                if (count[entry.first] < entry.second)
                {
                    comprehend = false;
                }
            }
            if (comprehend)
            {
                result += word.size();
            }
        }
        return result;
    }
};