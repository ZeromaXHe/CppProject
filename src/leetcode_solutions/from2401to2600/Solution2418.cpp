#include <iostream>
#include <vector>

using namespace std;

/**
 * 2418. 按身高排序 | 难度：简单
 */
class Solution2418
{
public:
    /**
     * 执行用时：32 ms, 在所有 C++ 提交中击败了 72.76% 的用户
     * 内存消耗：19.7 MB, 在所有 C++ 提交中击败了 67.83% 的用户
     * 通过测试用例：68 / 68
     */
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<int> idx(heights.size());
        for (int i = 0; i < heights.size(); ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&](const int &a, const int &b)
             { return heights[a] > heights[b]; });
        vector<string> result;
        for (int index : idx)
            result.emplace_back(names[index]);
        return result;
    }
};