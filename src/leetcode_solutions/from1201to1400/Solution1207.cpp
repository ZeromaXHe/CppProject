#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 1207. 独一无二的出现次数 | 难度：简单
 */
class Solution1207
{
public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 14.61% 的用户
     * 内存消耗：8 MB, 在所有 C++ 提交中击败了 31.23% 的用户
     * 通过测试用例：66 / 66
     */
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> count;
        for (int num : arr)
        {
            count[num]++;
        }
        unordered_set<int> set;
        for (auto &c : count)
        {
            set.insert(c.second);
        }
        return count.size() == set.size();
    }
};