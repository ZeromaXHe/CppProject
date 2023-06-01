#include <iostream>
#include <vector>

using namespace std;

/**
 * 1552. 两球之间的磁力 | 难度：中等
 */
class Solution1552
{
public:
    /**
     * 执行用时：252 ms, 在所有 C++ 提交中击败了 5.96% 的用户
     * 内存消耗：56.4 MB, 在所有 C++ 提交中击败了 88.89% 的用户
     * 通过测试用例：98 / 98
     */
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int right = position[n - 1] - position[0];
        int left = 0;
        int result = 0;
        while (right >= left)
        {
            int mid = (left + right) / 2;
            int count = 1;
            int pre = 0;
            for (int i = 1; i < n; ++i)
            {
                if (position[i] - position[pre] >= mid)
                {
                    ++count;
                    pre = i;
                }
            }
            if (count >= m)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};