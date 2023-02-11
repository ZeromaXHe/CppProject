#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 2335. 装满杯子需要的最短总时长 | 难度：简单
 */
class Solution2335
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 56.60% 的用户
     * 内存消耗：11.5 MB, 在所有 C++ 提交中击败了 6.25% 的用户
     * 通过测试用例：280 / 280
     */
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] < amount[2]) {
            return amount[2];
        } else {
            int sum = amount[0] + amount[1] + amount[2];
            return sum / 2 + sum % 2;
        }
    }
};
