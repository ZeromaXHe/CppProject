#include <iostream>
#include <vector>

using namespace std;

/**
 * 2469. 温度转换 | 难度：简单
 */
class Solution2469
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 26.14% 的用户
     * 内存消耗：5.9 MB, 在所有 C++ 提交中击败了 66.94% 的用户
     * 通过测试用例：74 / 74
     */
    vector<double> convertTemperature(double celsius)
    {
        return vector<double>{celsius + 273.15, celsius * 1.8 + 32.0};
    }
};
