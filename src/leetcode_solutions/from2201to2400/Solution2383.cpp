#include <iostream>
#include <vector>

using namespace std;

/**
 * 2383. 赢得比赛需要的最少训练时长 | 难度：简单
 */
class Solution2383
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 66.10% 的用户
     * 内存消耗：10.8 MB, 在所有 C++ 提交中击败了 67.37% 的用户
     * 通过测试用例：111 / 111
     */
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int n = energy.size();
        int energyNow = initialEnergy;
        int expNow = initialExperience;
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (energyNow <= energy[i]) {
                result += energy[i] - energyNow + 1;
                energyNow = energy[i] + 1;
            }
            if (expNow <= experience[i]) {
                result += experience[i] - expNow + 1;
                expNow = experience[i] + 1;
            }
            energyNow -= energy[i];
            expNow += experience[i];
        }
        return result;
    }
};
