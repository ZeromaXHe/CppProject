#include <iostream>
#include <vector>

using namespace std;

/**
 * 1287. 有序数组中出现次数超过25%的元素 | 难度：简单
 */
class Solution1287
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 90.30% 的用户
     * 内存消耗：12.2 MB, 在所有 C++ 提交中击败了 29.70% 的用户
     * 通过测试用例：25 / 25
     *
     * 可以用二分优化，那个思路厉害，4 次取样左右边界即可
     */
    int findSpecialInteger(vector<int> &arr)
    {
        int fourth = arr.size() / 4;
        for (int i = 0; i < arr.size() - fourth; ++i)
        {
            if (arr[i] == arr[i + fourth])
            {
                return arr[i];
            }
        }
        return -1;
    }
};