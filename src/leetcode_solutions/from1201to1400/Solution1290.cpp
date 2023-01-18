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
 * 1290. 二进制链表转整数 | 难度：简单
 */
class Solution1290
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：7.9 MB, 在所有 C++ 提交中击败了 92.70% 的用户
     * 通过测试用例：102 / 102
     */
    int getDecimalValue(ListNode *head)
    {
        ListNode *cur = head;
        int result = 0;
        while (cur != nullptr)
        {
            result <<= 1;
            result += cur->val;
            cur = cur->next;
        }
        return result;
    }
};