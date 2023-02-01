#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1394. 找出数组中的幸运数 | 难度：简单
 */
class Solution1394
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 88.20% 的用户
     * 内存消耗：10 MB, 在所有 C++ 提交中击败了 64.59% 的用户
     * 通过测试用例：101 / 101
     */
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> count;
        for (int i : arr)
        {
            ++count[i];
        }
        int result = -1;
        // 结构化绑定(c++ 17 特性)
        for (auto [k, v] : count)
        {
            if (k == v && k > result)
            {
                result = k;
            }
        }
        return result;
    }
};
