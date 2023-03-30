#include <iostream>
#include <vector>

using namespace std;

/**
 * 1637. 两点之间不包含任何点的最宽垂直区域 | 难度：中等
 */
class Solution1637
{
public:
    /**
     * 执行用时：268 ms, 在所有 C++ 提交中击败了 43.75% 的用户
     * 内存消耗：64.6 MB, 在所有 C++ 提交中击败了 81.94% 的用户
     * 通过测试用例：54 / 54
     */
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int maxi = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            maxi = max(maxi, points[i][0] - points[i - 1][0]);
        }
        return maxi;
    }
};
