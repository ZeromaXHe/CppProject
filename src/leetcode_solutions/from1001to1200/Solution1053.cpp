#include <iostream>
#include <vector>

using namespace std;

/**
 * 1053. 交换一次的先前排列 | 难度：中等
 */
class Solution1053
{
public:
    /**
     * 执行用时：24 ms, 在所有 C++ 提交中击败了 58.99% 的用户
     * 内存消耗：24.1 MB, 在所有 C++ 提交中击败了 52.52% 的用户
     * 通过测试用例：54 / 54
     */
    vector<int> prevPermOpt1(vector<int> &arr)
    {
        int n = arr.size();
        int i;
        for (i = n - 2; i >= 0; --i)
        {
            if (arr[i] > arr[i + 1])
                break;
        }
        if (i >= 0)
        {
            // 二分估计快些，而且 j 的边界校验其实可以省略
            int j = n - 1;
            while (j > i && arr[j] >= arr[i])
                --j;
            while (j - 1 > i && arr[j - 1] == arr[j])
                --j;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        return arr;
    }
};