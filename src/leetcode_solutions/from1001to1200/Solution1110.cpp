#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 1110. 删点成林 | 难度：中等
 */
class Solution1110
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
     * 执行用时：24 ms, 在所有 C++ 提交中击败了 48.39% 的用户
     * 内存消耗：24.7 MB, 在所有 C++ 提交中击败了 58.87% 的用户
     * 通过测试用例：111 / 111
     */
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode *> result;
        delNodes(root, nullptr, true, result, toDeleteSet);
        return result;
    }

    /**
     * toDeleteSet 漏使用 & 表示引用的话：
     * 执行用时：628 ms, 在所有 C++ 提交中击败了 5.24% 的用户
     * 内存消耗：181.1 MB, 在所有 C++ 提交中击败了 5.04% 的用户
     * 通过测试用例：111 / 111
     */
    void delNodes(TreeNode *root, TreeNode *parent, bool left, vector<TreeNode *> &result, unordered_set<int> &toDeleteSet)
    {
        if (root == nullptr)
            return;
        if (parent == nullptr)
        {
            if (toDeleteSet.find(root->val) == toDeleteSet.end())
            {
                result.emplace_back(root);
                delNodes(root->left, root, true, result, toDeleteSet);
                delNodes(root->right, root, false, result, toDeleteSet);
            }
            else
            {
                delNodes(root->left, nullptr, true, result, toDeleteSet);
                delNodes(root->right, nullptr, false, result, toDeleteSet);
                root->left = nullptr;
                root->right = nullptr;
            }
        }
        else if (toDeleteSet.find(root->val) == toDeleteSet.end())
        {
            delNodes(root->left, root, true, result, toDeleteSet);
            delNodes(root->right, root, false, result, toDeleteSet);
        }
        else
        {
            if (left)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delNodes(root->left, nullptr, true, result, toDeleteSet);
            delNodes(root->right, nullptr, false, result, toDeleteSet);
            root->left = nullptr;
            root->right = nullptr;
        }
    }
};