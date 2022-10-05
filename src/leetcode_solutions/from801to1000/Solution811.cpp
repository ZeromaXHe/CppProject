#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * 811. 子域名访问计数 | 难度：中等
 */
class Solution811
{
public:
    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了 85.51% 的用户
     * 内存消耗：11.4 MB, 在所有 C++ 提交中击败了 31.40% 的用户
     * 通过测试用例：52 / 52
     */
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        vector<string> res;
        unordered_map<string, int> counts;
        for (string cpdomain : cpdomains)
        {
            int space = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, space));
            string domain = cpdomain.substr(space + 1);
            counts[domain] += count;
            for (int i = 0; i < domain.size(); i++)
            {
                if (domain[i] == '.')
                {
                    string subdomain = domain.substr(i + 1);
                    counts[subdomain] += count;
                }
            }
        }
        for (auto &&[subdomain, count] : counts)
        {
            res.emplace_back(to_string(count) + " " + subdomain);
        }
        return res;
    }
};