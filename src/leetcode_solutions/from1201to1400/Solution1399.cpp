#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1399. 统计最大组的数目 | 难度：简单
 */
class Solution1399
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 82.03% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 95.31% 的用户
     * 通过测试用例：75 / 75
     */
    int countLargestGroup(int n)
    {
        int count[37];
        // C++ 数组没有默认值
        for (int i = 1; i <= 36; ++i)
        {
            count[i] = 0;
        }
        for (int i = 0; i <= n; ++i)
        {
            int tmp = i;
            int sum = 0;
            while (tmp > 0)
            {
                sum += (tmp % 10);
                tmp /= 10;
            }
            ++count[sum];
        }
        int max = 0;
        int maxCount = 0;
        for (int i = 1; i <= 36; ++i)
        {
            if (count[i] > max)
            {
                max = count[i];
                maxCount = 1;
            }
            else if (count[i] == max)
            {
                ++maxCount;
            }
        }
        return maxCount;
    }
};
