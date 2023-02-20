#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 2347. 最好的扑克手牌 | 难度：简单
 */
class Solution2347
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 47.62% 的用户
     * 内存消耗：9.9 MB, 在所有 C++ 提交中击败了 64.55% 的用户
     * 通过测试用例：98 / 98
     */
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        unordered_set<char> set;
        for (char suit : suits)
        {
            set.emplace(suit);
        }
        if (set.size() == 1)
        {
            return "Flush";
        }
        unordered_map<int, int> map;
        for (int rank : ranks)
        {
            ++map[rank];
        }
        if (map.size() == 5)
        {
            return "High Card";
        }
        for (auto [_, v] : map)
        {
            if (v > 2)
            {
                return "Three of a Kind";
            }
        }
        return "Pair";
    }
};
