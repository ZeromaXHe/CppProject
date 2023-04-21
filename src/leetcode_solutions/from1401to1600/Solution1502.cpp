#include <iostream>
#include <vector>

using namespace std;

/**
 * 1502. 判断能否形成等差数列 | 难度：简单
 */
class Solution1502
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：8.8 MB, 在所有 C++ 提交中击败了 81.64% 的用户
     * 通过测试用例：109 / 109
     */
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 2; i < arr.size(); ++i)
        {
            if (arr[i] + arr[i - 2] != 2 * arr[i - 1])
                return false;
        }
        return true;
    }
};