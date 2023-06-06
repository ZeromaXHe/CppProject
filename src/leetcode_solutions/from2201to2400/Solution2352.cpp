#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 2352. 相等行列对 | 难度：中等
 */
class Solution2352
{
public:
    /**
     * 看其他人的提交和官方题解，应该可以直接用 vector 做 map 的 key，少了字符串的拼接会快很多
     * 
     * 执行用时：276 ms, 在所有 C++ 提交中击败了 24.25% 的用户
     * 内存消耗：43 MB, 在所有 C++ 提交中击败了 18.86% 的用户
     * 通过测试用例：72 / 72
     */
    int equalPairs(vector<vector<int>> &grid)
    {
        unordered_map<string, int> map;
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            string s = "";
            for (int j = 0; j < n; ++j)
            {
                s += to_string(grid[i][j]);
                s += ",";
            }
            ++map[s];
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            string s = "";
            for (int j = 0; j < n; ++j)
            {
                s += to_string(grid[j][i]);
                s += ",";
            }
            result += map[s];
        }
        return result;
    }
};