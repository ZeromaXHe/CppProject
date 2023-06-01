#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 407. 接雨水 II | 难度：困难
 */
class Solution407
{
public:
    /**
     * 官方题解
     * 
     * 执行用时：48 ms, 在所有 C++ 提交中击败了 91.53% 的用户
     * 内存消耗：12.4 MB, 在所有 C++ 提交中击败了 88.02% 的用户
     * 通过测试用例：42 / 42
     */
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
        {
            return 0;
        }
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        // 将最外层边缘放进 pq 和 visit
        for (int i = 0; i < m; ++i)
        {
            pq.push({heightMap[i][0], i * n});
            pq.push({heightMap[i][n - 1], i * n + n - 1});
            visit[i][0] = true;
            visit[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j)
        {
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[m - 1][j], (m - 1) * n + j});
            visit[0][j] = true;
            visit[m - 1][j] = true;
        }

        int res = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        while (!pq.empty())
        {
            // 获取边缘高度最小值
            pair<int, int> curr = pq.top();
            pq.pop();
            // 一种新奇的遍历周围四个方向的写法
            for (int k = 0; k < 4; ++k)
            {
                int nx = curr.second / n + dirs[k];
                int ny = curr.second % n + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny])
                {
                    // 如果边缘旁的高度小于边缘，计算可以蓄的水量
                    if (heightMap[nx][ny] < curr.first)
                    {
                        res += curr.first - heightMap[nx][ny];
                    }
                    // 将新的边缘放入 pq 和更新 visit
                    visit[nx][ny] = true;
                    pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
                }
            }
        }

        return res;
    }
};