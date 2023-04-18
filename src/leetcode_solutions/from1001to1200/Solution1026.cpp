#include <iostream>
#include <vector>

using namespace std;

/**
 * 1026. 节点与其祖先之间的最大差值 | 难度：中等
 */
class Solution1026
{
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：10.3 MB, 在所有 C++ 提交中击败了 36.21% 的用户
     * 通过测试用例：28 / 28
     */
    int maxAncestorDiff(TreeNode *root)
    {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode *root, int mi, int ma)
    {
        if (root == nullptr)
            return 0;
        int diff = max(::abs(root->val - mi), ::abs(root->val - ma));
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        diff = max(diff, dfs(root->left, mi, ma));
        diff = max(diff, dfs(root->right, mi, ma));
        return diff;
    }
};