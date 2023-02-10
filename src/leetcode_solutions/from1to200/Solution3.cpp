#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 3. 无重复字符的最长子串 | 难度：中等
 */
class Solution3
{
public:
    /**
     * 执行用时：16 ms, 在所有 C++ 提交中击败了 70.09% 的用户
     * 内存消耗：8.7 MB, 在所有 C++ 提交中击败了 50.79% 的用户
     * 通过测试用例：987 / 987
     */
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;
        int from = 0;
        int max = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (set.find(s[i]) == set.end())
            {
                set.insert(s[i]);
                max = std::max(max, i + 1 - from);
            }
            else
            {
                while (s[from] != s[i])
                {
                    set.erase(s[from++]);
                }
                ++from;
            }
        }
        return max;
    }

    /**
     * 参考提交里面最快的写法写的，其实可以等效替换为 unordered_map
     * 其实就是发现重复时，from 直接跳到上次的索引位置后一个即可，不需要像上面 set 那样一个一个检查。
     * 
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 88.77% 的用户
     * 内存消耗：7.4 MB, 在所有 C++ 提交中击败了 79.70% 的用户
     * 通过测试用例：987 / 987
     */
    int lengthOfLongestSubstring_charLastIdxVector(string s)
    {
        vector<int> lastIdx(128, -1);
        int ans = 0;
        for (int to = 0, from = 0; to < s.length(); ++to)
        {
            from = max(from, lastIdx[s[to]] + 1);
            ans = max(ans, to - from + 1);
            lastIdx[s[to]] = to;
        }
        return ans;
    }
};
