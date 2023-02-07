#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1604. 警告一小时内使用相同员工卡大于等于三次的人 | 难度：中等
 */
class Solution1604
{
public:
    /**
     * 执行用时：184 ms, 在所有 C++ 提交中击败了 95.89% 的用户
     * 内存消耗：97.4 MB, 在所有 C++ 提交中击败了 69.86% 的用户
     * 通过测试用例：77 / 77
     */
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        unordered_map<string, vector<int>> map;
        int n = keyName.size();
        for (int i = 0; i < n; ++i)
        {
            string time = keyTime[i];
            map[keyName[i]].emplace_back(((time[0] - '0') * 10 + (time[1] - '0')) * 60 + ((time[3] - '0') * 10 + (time[4] - '0')));
        }
        vector<string> res;
        for (auto &[name, list] : map)
        {
            sort(list.begin(), list.end());
            int size = list.size();
            for (int i = 2; i < size; ++i)
            {
                if (list[i] - list[i - 2] <= 60)
                {
                    res.emplace_back(name);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
