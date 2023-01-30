#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 391. 完美矩形 | 难度：困难
 */
class Solution391
{
public:
    /**
     * 参考题解做的
     *
     * 执行用时：92 ms, 在所有 C++ 提交中击败了 92.27% 的用户
     * 内存消耗：31.5 MB, 在所有 C++ 提交中击败了 39.05% 的用户
     * 通过测试用例：49 / 49
     */
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        long long area = 0;
        int minX = rectangles[0][0];
        int minY = rectangles[0][1];
        int maxX = rectangles[0][2];
        int maxY = rectangles[0][3];
        unordered_map<long long, int> count;
        for (auto &rect : rectangles)
        {
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];
            area += (long long)(x2 - x1) * (y2 - y1);
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);
            ++count[x1 * 100000LL + y1];
            ++count[x1 * 100000LL + y2];
            ++count[x2 * 100000LL + y1];
            ++count[x2 * 100000LL + y2];
        }
        if (area != (long long)(maxX - minX) * (maxY - minY) ||
            !count.count(minX * 100000LL + minY) ||
            !count.count(minX * 100000LL + maxY) ||
            !count.count(maxX * 100000LL + minY) ||
            !count.count(maxX * 100000LL + maxY))
        {
            return false;
        }
        count.erase(minX * 100000LL + minY);
        count.erase(minX * 100000LL + maxY);
        count.erase(maxX * 100000LL + minY);
        count.erase(maxX * 100000LL + maxY);
        for (auto &entry : count)
        {
            int value = entry.second;
            if (value != 2 && value != 4)
            {
                return false;
            }
        }
        return true;
    }
};
