#include <iostream>
#include <vector>

using namespace std;

/**
 * 1337. 矩阵中战斗力最弱的 K 行 | 难度：简单
 */
class Solution1337
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 63.85% 的用户
     * 内存消耗：10.1 MB, 在所有 C++ 提交中击败了 84.74% 的用户
     * 通过测试用例：52 / 52
     */
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> sorting;
        for (int i = 0; i < n; i++)
        {
            sorting.push_back(i);
        }
        // []：定义匿名函数
        // [&]：以引用形式捕获所有外部变量，也就是外部变量均可用
        // 因为 军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前，所以可以直接比 mat[a] < mat[b]
        sort(sorting.begin(), sorting.end(), [&](const int &a, const int &b)
             { return mat[a] == mat[b] ? a < b : mat[a] < mat[b]; });
        vector<int> r(sorting.begin(), sorting.begin() + k);
        return r;
    }
};
