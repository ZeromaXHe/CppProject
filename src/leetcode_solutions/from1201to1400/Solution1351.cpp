#include <iostream>
#include <vector>

using namespace std;

/**
 * 1351. 统计有序矩阵中的负数 | 难度：简单
 */
class Solution1351
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 87.44% 的用户
     * 内存消耗：10.1 MB, 在所有 C++ 提交中击败了 64.30% 的用户
     * 通过测试用例：44 / 44
     * 
     * 类似之前搜索有序二维矩阵的思路，从对角线开始，等同于二分了。
     */
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0, j = grid[0].size() - 1; i < grid.size() && j >= 0;)
        {
            if (grid[i][j] >= 0)
            {
                i++;
            }
            else
            {
                count += grid.size() - i;
                j--;
            }
        }
        return count;
    }
};
