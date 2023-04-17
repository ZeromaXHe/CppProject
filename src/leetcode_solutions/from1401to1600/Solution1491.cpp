#include <iostream>
#include <vector>

using namespace std;

/**
 * 1491. 去掉最低工资和最高工资后的工资平均值 | 难度：简单
 */
class Solution1491
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6.8 MB, 在所有 C++ 提交中击败了 72.44% 的用户
     * 通过测试用例：43 / 43
     */
    double average(vector<int> &salary)
    {
        int max = 0;
        int min = INT32_MAX;
        double sum = 0.0;
        for (int s : salary)
        {
            if (s > max)
                max = s;
            if (s < min)
                min = s;
            sum += s;
        }
        return (sum - max - min) / (salary.size() - 2.0);
    }
};