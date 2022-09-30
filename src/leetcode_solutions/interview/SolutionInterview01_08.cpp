#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 面试题 01.08. 零矩阵 | 难度：中等
 */
class Solution
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 88.13% 的用户
     * 内存消耗：11.8 MB, 在所有 C++ 提交中击败了 66.68% 的用户
     * 通过测试用例：159 / 159
     */
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool firstRow = false;
        bool firstCol = false;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
                firstCol = true;
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == 0)
                firstRow = true;
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (firstCol)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }

        if (firstRow)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};