#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 2404. 出现最频繁的偶数元素 | 难度：简单
 */
class Solution2404
{
public:
    /**
     * 执行用时：76 ms, 在所有 C++ 提交中击败了 40.89% 的用户
     * 内存消耗：44.3 MB, 在所有 C++ 提交中击败了 19.71% 的用户
     * 通过测试用例：219 / 219
     */
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int num : nums)
        {
            ++map[num];
        }
        int count = 0;
        int res = -1;
        for (auto [n, c] : map)
        {
            if (n % 2 == 1)
                continue;
            if (c > count || (c == count && n < res))
            {
                res = n;
                count = c;
            }
        }
        return res;
    }
};