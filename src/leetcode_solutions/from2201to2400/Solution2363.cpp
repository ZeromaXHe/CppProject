#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

/**
 * 2363. 合并相似的物品 | 难度：简单
 */
class Solution2363
{
public:
    /**
     * 执行用时：32 ms, 在所有 C++ 提交中击败了 39.43% 的用户
     * 内存消耗：17.1 MB, 在所有 C++ 提交中击败了 23.98% 的用户
     * 通过测试用例：49 / 49
     */
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        unordered_map<int, int> map;
        for (auto item : items1)
            map[item[0]] += item[1];
        for (auto item : items2)
            map[item[0]] += item[1];
        vector<vector<int>> res;
        for (auto [k, v] : map)
            res.emplace_back(vector<int>{k, v});
        sort(res.begin(), res.end(), [&](const auto &a, const auto &b)
             { return a[0] < b[0]; });
        return res;
    }

    /**
     * 执行用时：32 ms, 在所有 C++ 提交中击败了 39.43% 的用户
     * 内存消耗：17.2 MB, 在所有 C++ 提交中击败了 17.48% 的用户
     * 通过测试用例：49 / 49
     */
    vector<vector<int>> mergeSimilarItems_map(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> map;
        for (auto item : items1)
            map[item[0]] += item[1];
        for (auto item : items2)
            map[item[0]] += item[1];
        vector<vector<int>> res;
        for (auto [k, v] : map)
            res.emplace_back(vector<int>{k, v});
        return res;
    }
};
