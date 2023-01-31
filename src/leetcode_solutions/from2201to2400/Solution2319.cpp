#include <iostream>
#include <vector>

using namespace std;

/**
 * 2319. 判断矩阵是否是一个 X 矩阵 | 难度：简单
 */
class Solution2319
{
public:
    /**
     * 执行用时：32 ms, 在所有 C++ 提交中击败了 49.32% 的用户
     * 内存消耗：15.9 MB, 在所有 C++ 提交中击败了 17.35% 的用户
     * 通过测试用例：84 / 84
     */
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int len = grid.size();
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                if (i == j || i == len - 1 - j)
                {
                    if (grid[i][j] == 0)
                        return false;
                }
                else
                {
                    if (grid[i][j] != 0)
                        return false;
                }
            }
        }
        return true;
    }
};
