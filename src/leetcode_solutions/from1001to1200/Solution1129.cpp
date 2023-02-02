#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * 1129. 颜色交替的最短路径 | 难度：中等
 */
class Solution1129
{
public:
    /**
     * 执行用时：20 ms, 在所有 C++ 提交中击败了 49.34% 的用户
     * 内存消耗：15.4 MB, 在所有 C++ 提交中击败了 20.20% 的用户
     * 通过测试用例：90 / 90
     */
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        unordered_map<int, vector<int>> redMap;
        for (vector<int> redEdge : redEdges)
        {
            if (!redMap.count(redEdge[0]))
                redMap[redEdge[0]] = vector<int>{redEdge[1]};
            else
                redMap[redEdge[0]].emplace_back(redEdge[1]);
        }
        unordered_map<int, vector<int>> blueMap;
        for (vector<int> blueEdge : blueEdges)
        {
            if (!blueMap.count(blueEdge[0]))
                blueMap[blueEdge[0]] = vector<int>{blueEdge[1]};
            else
                blueMap[blueEdge[0]].emplace_back(blueEdge[1]);
        }
        vector<int> resultRed(n, -1);
        resultRed[0] = 0;
        vector<int> resultBlue(n, -1);
        resultBlue[0] = 0;
        queue<int> redQueue;
        for (int to : redMap[0])
        {
            redQueue.push(to);
            resultRed[to] = 1;
        }
        queue<int> blueQueue;
        for (int to : blueMap[0])
        {
            blueQueue.push(to);
            resultBlue[to] = 1;
        }
        int dist = 2;
        // 一开始用 C++ 都忘记 BFS 可以计数来避免引入一个临时容器了…… 看之前 C# 代码才想起来
        while (!redQueue.empty() || !blueQueue.empty())
        {
            int redCount = redQueue.size();
            int blueCount = blueQueue.size();
            for (int i = 0; i < redCount; ++i)
            {
                int red = redQueue.front();
                redQueue.pop();
                if (!blueMap.count(red))
                    continue;
                for (int blue : blueMap[red])
                {
                    if (resultBlue[blue] == -1)
                    {
                        resultBlue[blue] = dist;
                        blueQueue.push(blue);
                    }
                }
            }
            for (int i = 0; i < blueCount; ++i)
            {
                int blue = blueQueue.front();
                blueQueue.pop();
                if (!redMap.count(blue))
                    continue;
                for (int red : redMap[blue])
                {
                    if (resultRed[red] == -1)
                    {
                        resultRed[red] = dist;
                        redQueue.push(red);
                    }
                }
            }
            ++dist;
        }
        vector<int> result{0};
        for (int i = 1; i < n; ++i)
        {
            if (resultRed[i] == -1)
                result.emplace_back(resultBlue[i]);
            else if (resultBlue[i] == -1)
                result.emplace_back(resultRed[i]);
            else
                result.emplace_back(min(resultRed[i], resultBlue[i]));
        }
        return result;
    }
};
