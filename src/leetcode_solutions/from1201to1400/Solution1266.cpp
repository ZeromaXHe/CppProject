#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

/**
 * 1266. 访问所有点的最小时间 | 难度：简单
 */
class Solution1266
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 76.15% 的用户
     * 内存消耗：9.9 MB, 在所有 C++ 提交中击败了 25.94% 的用户
     * 通过测试用例：122 / 122
     */
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int result = 0;
        int x = points[0][0];
        int y = points[0][1];
        for (auto &point : points)
        {
            // abs 不加 :: 的话会报错不明确
            result += max(::abs(point[0] - x), ::abs(point[1] - y));
            x = point[0];
            y = point[1];
        }
        return result;
    }
};