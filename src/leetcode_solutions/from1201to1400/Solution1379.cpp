#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 1379. 找出克隆二叉树中的相同节点 | 难度：简单
 */
class Solution1379
{
    TreeNode *preOrderFinder(TreeNode *node, TreeNode *target)
    {
        if (node->val == target->val)
            return node;
        if (node->left != nullptr)
        {
            TreeNode *result = preOrderFinder(node->left, target);
            if (result != nullptr)
                return result;
        }
        if (node->right != nullptr)
        {
            TreeNode *result = preOrderFinder(node->right, target);
            if (result != nullptr)
                return result;
        }
        return nullptr;
    }

public:
    /**
     * 执行用时：480 ms, 在所有 C++ 提交中击败了 41.25% 的用户
     * 内存消耗：160.1 MB, 在所有 C++ 提交中击败了 35.01% 的用户
     * 通过测试用例：56 / 56
     */
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        return preOrderFinder(cloned, target);
    }
};
