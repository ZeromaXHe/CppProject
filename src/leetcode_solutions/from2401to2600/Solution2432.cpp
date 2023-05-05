#include <iostream>
#include <vector>

using namespace std;

/**
 * 2432. 处理用时最长的那个任务的员工 | 难度：简单
 */
class Solution2432
{
public:
    /**
     * 执行用时：76 ms, 在所有 C++ 提交中击败了 21.23% 的用户
     * 内存消耗：34.6 MB, 在所有 C++ 提交中击败了 49.53% 的用户
     * 通过测试用例：514 / 514
     */
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int maxIdx = logs[0][0], maxCost = logs[0][1];
        for (int i = 1; i < logs.size(); ++i)
        {
            int idx = logs[i][0];
            int cost = logs[i][1] - logs[i - 1][1];
            if (cost > maxCost || (cost == maxCost && idx < maxIdx))
            {
                maxIdx = idx;
                maxCost = cost;
            }
        }
        return maxIdx;
    }
};