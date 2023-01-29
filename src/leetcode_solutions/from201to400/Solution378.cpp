#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 378. 有序矩阵中第 K 小的元素 | 难度：中等
 */
class Solution378
{
    bool check(vector<vector<int>> &matrix, int mid, int k, int n)
    {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] <= mid)
            {
                num += i + 1;
                j++;
            }
            else
            {
                i--;
            }
        }
        return num >= k;
    }

public:
    /**
     * 参考题解做的
     *
     * 执行用时：20 ms, 在所有 C++ 提交中击败了 92.39% 的用户
     * 内存消耗：12.7 MB, 在所有 C++ 提交中击败了 87.57% 的用户
     * 通过测试用例：86 / 86
     */
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
