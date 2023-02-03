#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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
 * 1145. 二叉树着色游戏 | 难度：中等
 */
class Solution1145
{
    int preOrderFindX(TreeNode *node, int x, TreeNode *&outFind)
    {
        if (node->val == x)
        {
            outFind = node;
            return 0;
        }
        int count = 1;
        if (node->left != nullptr)
        {
            int result = preOrderFindX(node->left, x, outFind);
            if (result >= 0)
            {
                if (node->right != nullptr)
                    count -= preOrderFindX(node->right, x, outFind);
                return result + count;
            }
            else
                count -= result;
        }
        if (node->right != nullptr)
        {
            int result = preOrderFindX(node->right, x, outFind);
            if (result >= 0)
                return result + count;
            else
                count -= result;
        }
        return -count;
    }

    int preOrderCountSubTree(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int count = 1;
        if (node->left != nullptr)
            count += preOrderCountSubTree(node->left);
        if (node->right != nullptr)
            count += preOrderCountSubTree(node->right);
        return count;
    }

public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 62.61% 的用户
     * 内存消耗：10.3 MB, 在所有 C++ 提交中击败了 90.43% 的用户
     * 通过测试用例：65 / 65
     */
    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        TreeNode *node = root;
        int upperCount = preOrderFindX(node, x, node);
        int mostCount = max(max(upperCount, preOrderCountSubTree(node->left)), preOrderCountSubTree(node->right));
        // n 是奇数
        return mostCount > n / 2;
    }
};
