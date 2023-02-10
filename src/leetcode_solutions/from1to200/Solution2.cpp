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
 * 2. 两数相加 | 难度：中等
 */
class Solution2
{
public:
    /**
     * 执行用时：28 ms, 在所有 C++ 提交中击败了 57.80% 的用户
     * 内存消耗：69.5 MB, 在所有 C++ 提交中击败了 25.83% 的用户
     * 通过测试用例：1568 / 1568
     */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        // C++ 直接用变量就可以当 bool 用，还是不太习惯
        while (p1 || p2 || carry)
        {
            int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            p->next = new ListNode(sum % 10);
            p = p->next;
            carry = sum / 10;
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
        }
        return dummy->next;
    }
};
