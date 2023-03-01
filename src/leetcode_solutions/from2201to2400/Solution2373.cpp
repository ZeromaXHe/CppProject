#include <iostream>
#include <vector>

using namespace std;

/**
 * 2373. 矩阵中的局部最大值 | 难度：简单
 */
class Solution2373
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 87.60% 的用户
     * 内存消耗：10.8 MB, 在所有 C++ 提交中击败了 45.35% 的用户
     * 通过测试用例：50 / 50
     */
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> result = vector(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = -2; k < 1; ++k)
                {
                    if (i + k < 0 || i + k >= n - 2)
                        continue;
                    for (int m = -2; m < 1; ++m)
                    {
                        if (j + m < 0 || j + m >= n - 2)
                            continue;
                        if (grid[i][j] > result[i + k][j + m])
                            result[i + k][j + m] = grid[i][j];
                    }
                }
            }
        }
        return result;
    }
};
