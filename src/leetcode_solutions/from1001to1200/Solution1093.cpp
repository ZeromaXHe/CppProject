#include <iostream>
#include <vector>

using namespace std;

/**
 * 1093. 大样本统计 | 难度：中等
 */
class Solution1093
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 77.32% 的用户
     * 内存消耗：8 MB, 在所有 C++ 提交中击败了 89.69% 的用户
     * 通过测试用例：52 / 52
     */
    vector<double> sampleStats(vector<int> &count)
    {
        int sumCount = 0;
        for (int c : count)
            sumCount += c;
        vector<double> result = {-1, -1, -1, -1, -1};
        double sum = 0;
        int maxCount = 0;
        int sumCountLeft = 0;
        int leftMedian = -1;
        for (int i = 0; i < count.size(); ++i)
        {
            sum += (double)i * count[i];
            sumCountLeft += count[i];
            if (sumCount % 2 == 0)
            {
                if (leftMedian == -1 && sumCountLeft == sumCount / 2)
                    leftMedian = i;
                else if (result[3] == -1 && sumCountLeft > sumCount / 2)
                {
                    if (leftMedian == -1)
                        result[3] = i;
                    else
                        result[3] = (leftMedian + i) / 2.0;
                }
            }
            else if (result[3] == -1 && sumCountLeft > sumCount / 2)
                result[3] = i;

            if (count[i] > 0)
            {
                result[1] = i;
                if (result[0] == -1)
                    result[0] = i;
                if (count[i] > maxCount)
                {
                    result[4] = i;
                    maxCount = count[i];
                }
            }
        }
        result[2] = sum / sumCount;
        return result;
    }
};