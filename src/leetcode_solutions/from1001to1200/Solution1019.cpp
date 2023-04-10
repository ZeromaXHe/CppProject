#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * 1019. 链表中的下一个更大节点 | 难度：中等
 */
class Solution1019
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    /**
     * 执行用时：108 ms, 在所有 C++ 提交中击败了 24.68% 的用户
     * 内存消耗：41.7 MB, 在所有 C++ 提交中击败了 39.48% 的用户
     * 通过测试用例：76 / 76
     */
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ans;
        stack<pair<int, int>> s;

        ListNode *node = head;
        int idx = 0;
        while (node)
        {
            ans.push_back(0);
            while (!s.empty() && s.top().first < node->val)
            {
                ans[s.top().second] = node->val;
                s.pop();
            }
            s.emplace(node->val, idx);
            node = node->next;
            ++idx;
        }
        return ans;
    }
};