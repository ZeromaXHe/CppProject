#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

/**
 * 1233. 删除子文件夹 | 难度：中等
 */
class Solution1233
{
    struct Trie
    {
        Trie() : ref(-1) {}

        unordered_map<string, Trie *> children;
        int ref;
    };

public:
    /**
     * 参考题解做的
     *
     * 执行用时：340 ms, 在所有 C++ 提交中击败了 18.46% 的用户
     * 内存消耗：174.3 MB, 在所有 C++ 提交中击败了 11.54% 的用户
     * 通过测试用例：32 / 32
     */
    vector<string> removeSubfolders(vector<string> &folder)
    {
        auto split = [](const string &s) -> vector<string>
        {
            vector<string> ret;
            string cur;
            for (char ch : s)
            {
                if (ch == '/')
                {
                    // move 将参数转换为右值引用
                    ret.push_back(move(cur));
                    cur.clear();
                }
                else
                {
                    cur.push_back(ch);
                }
            }
            ret.push_back(move(cur));
            return ret;
        };

        Trie *root = new Trie();
        for (int i = 0; i < folder.size(); ++i)
        {
            vector<string> path = split(folder[i]);
            Trie *cur = root;
            for (const string &name : path)
            {
                if (!cur->children.count(name))
                {
                    cur->children[name] = new Trie();
                }
                cur = cur->children[name];
            }
            cur->ref = i;
        }

        vector<string> ans;

        function<void(Trie *)> dfs = [&](Trie *cur)
        {
            if (cur->ref != -1)
            {
                ans.push_back(folder[cur->ref]);
                return;
            }
            for (auto &&[_, child] : cur->children)
            {
                dfs(child);
            }
        };

        dfs(root);
        return ans;
    }
};
