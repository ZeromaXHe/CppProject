#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 1091. 二进制矩阵中的最短路径 | 难度：中等
 */
class Solution1091
{
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

public:
    /**
     * 执行用时：44 ms, 在所有 C++ 提交中击败了 91.20% 的用户
     * 内存消耗：18.7 MB, 在所有 C++ 提交中击败了 69.52% 的用户
     * 通过测试用例：89 / 89
     */
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        int dist = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; ++i)
            {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return dist;
                for (auto [dirX, dirY] : dir)
                {
                    int newX = x + dirX;
                    int newY = y + dirY;
                    if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0)
                    {
                        q.push({newX, newY});
                        grid[newX][newY] = 1;
                    }
                }
            }
            ++dist;
        }
        return -1;
    }
};