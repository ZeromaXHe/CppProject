#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 1669. 合并两个链表 | 难度：中等
 */
class Solution1669
{
public:
    /**
     * [0,3,2,1,4,5]
     * 3
     * 4
     * [1000000,1000001,1000002]
     * 这个示例的结果是 [0,3,2,1000000,1000001,1000002,5]，下标其实指的就是第几个 node，这就很傻逼了……一开始用 val 判断的
     *
     * 执行用时：320 ms, 在所有 C++ 提交中击败了 7.54% 的用户
     * 内存消耗：92.1 MB, 在所有 C++ 提交中击败了 69.85% 的用户
     * 通过测试用例：61 / 61
     *
     * 不知道为啥我这个就很慢
     */
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *nodeApre = list1;
        for (int i = 1; i < a; ++i)
        {
            nodeApre = nodeApre->next;
        }
        ListNode *nodeB = nodeApre;
        for (int i = 0; i <= b - a; ++i)
        {
            nodeB = nodeB->next;
        }
        nodeApre->next = list2;
        ListNode *node2end = list2;
        while (node2end->next != nullptr)
        {
            node2end = node2end->next;
        }
        node2end->next = nodeB->next;
        nodeB->next = nullptr;
        return list1;
    }
};
