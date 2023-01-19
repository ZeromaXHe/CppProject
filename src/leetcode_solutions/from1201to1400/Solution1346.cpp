#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 1346. 检查整数及其两倍数是否存在 | 难度：简单
 */
class Solution1346
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：10 MB, 在所有 C++ 提交中击败了 32.24% 的用户
     * 通过测试用例：108 / 108
     */
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> set;
        for (int i : arr)
        {
            if (i % 2 == 0)
            {
                if (set.count(i / 2) || set.count(i * 2))
                {
                    return true;
                }
            }
            else
            {
                if (set.count(i * 2))
                {
                    return true;
                }
            }
            set.insert(i);
        }
        return false;
    }
};
