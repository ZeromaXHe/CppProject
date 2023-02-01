#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 2325. 解密消息 | 难度：简单
 */
class Solution2325
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 71.94% 的用户
     * 内存消耗：6.8 MB, 在所有 C++ 提交中击败了 57.71% 的用户
     * 通过测试用例：69 / 69
     */
    string decodeMessage(string key, string message)
    {
        string abc = "abcdefghijklmnopqrstuvwxyz";
        unordered_map<char, char> map;
        int idx = 0;
        for (int i = 0; i < 26; ++i)
        {
            while (key[idx] == ' ' || map.count(key[idx]))
            {
                ++idx;
            }
            map[key[idx]] = abc[i];
        }
        // 直接在 message 上原地修改
        for (char &c : message)
        {
            if (c != ' ')
            {
                c = map[c];
            }
        }
        return message;
    }

    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6.7 MB, 在所有 C++ 提交中击败了 74.70% 的用户
     * 通过测试用例：69 / 69
     */
    string decodeMessage_char(string key, string message)
    {
        char decode = 'a';
        unordered_map<char, char> map;
        for (char c : key)
        {
            if (c != ' ' && !map.count(c))
            {
                map[c] = decode++;
            }
        }
        // 直接在 message 上原地修改
        for (char &c : message)
        {
            if (c != ' ')
            {
                c = map[c];
            }
        }
        return message;
    }
};
