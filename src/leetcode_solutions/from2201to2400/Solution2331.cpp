#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 2331. 计算布尔二叉树的值 | 难度：简单
 */
class Solution2331
{
public:
    /**
     * 执行用时：20 ms, 在所有 C++ 提交中击败了 6.44% 的用户
     * 内存消耗：14.7 MB, 在所有 C++ 提交中击败了 7.56% 的用户
     * 通过测试用例：75 / 75
     */
    bool evaluateTree(TreeNode *root)
    {
        if (root->val <= 1)
            return root->val == 1;
        if (root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};
