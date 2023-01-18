#include <iostream>
#include <vector>

using namespace std;

/**
 * 1299. 将每个元素替换为右侧最大元素 | 难度：简单
 */
class Solution1299
{
public:
    /**
     * 执行用时：92 ms, 在所有 C++ 提交中击败了 31.76% 的用户
     * 内存消耗：66.8 MB, 在所有 C++ 提交中击败了 47.24% 的用户
     * 通过测试用例：90 / 90
     */
    vector<int> replaceElements(vector<int> &arr)
    {
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            int nextMax = arr[i] > max ? arr[i] : max;
            arr[i] = max;
            max = nextMax;
        }
        return arr;
    }
};