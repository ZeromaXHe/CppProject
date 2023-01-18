#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

/**
 * 914. 卡牌分组 | 难度：简单
 */
class Solution914
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 95.28% 的用户
     * 内存消耗：17.1 MB, 在所有 C++ 提交中击败了 22.00% 的用户
     * 通过测试用例：74 / 74
     */
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> number_map;
        for (int num : deck)
        {
            number_map[num]++;
        }
        int gcdResult = number_map.begin()->second;
        for (auto &iter : number_map)
        {
            gcdResult = gcd(iter.second, gcdResult);
        }
        return gcdResult >= 2;
    }
};