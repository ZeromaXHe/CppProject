#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1487. 保证文件名唯一 | 难度：中等
 */
class Solution1487
{
public:
    /**
     * 执行用时：176 ms, 在所有 C++ 提交中击败了 40.98% 的用户
     * 内存消耗：64.2 MB, 在所有 C++ 提交中击败了 63.94% 的用户
     * 通过测试用例：33 / 33
     */
    vector<string> getFolderNames(vector<string> &names)
    {
        unordered_map<string, int> map;
        vector<string> res;
        for (string name : names)
        {
            if (map.find(name) != map.end())
            {
                int count = map[name];
                string next = name + "(" + to_string(count) + ")";
                while (map.find(next) != map.end())
                {
                    ++count;
                    next = name + "(" + to_string(count) + ")";
                }
                map[name] = count + 1;
                map[next] = 1;
                res.emplace_back(next);
            }
            else
            {
                map[name] = 1;
                res.emplace_back(name);
            }
        }
        return res;
    }
};
