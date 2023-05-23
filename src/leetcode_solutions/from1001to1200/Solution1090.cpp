#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1090. 受标签影响的最大值 | 难度：中等
 */
class Solution1090
{
public:
    /**
     * 执行用时：20 ms, 在所有 C++ 提交中击败了 97.09% 的用户
     * 内存消耗：19.8 MB, 在所有 C++ 提交中击败了 59.30% 的用户
     * 通过测试用例：81 / 81
     */
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        vector<pair<int, int>> valAndLabels;
        int n = values.size();
        for (int i = 0; i < n; ++i)
        {
            valAndLabels.emplace_back(pair<int, int>(values[i], labels[i]));
        }
        sort(valAndLabels.begin(), valAndLabels.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });
        int sum = 0;
        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i)
        {
            if (count == numWanted)
                break;
            if (map[valAndLabels[i].second] < useLimit)
            {
                sum += valAndLabels[i].first;
                ++count;
                ++map[valAndLabels[i].second];
            }
        }
        return sum;
    }
};