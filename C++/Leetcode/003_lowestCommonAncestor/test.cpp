#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        // 从下往上回溯
        TreeNode *leftResult = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightResult = lowestCommonAncestor(root->right, p, q);

        // 如果左右两边都传回了非空指针，说明 p 和 q 分别在当前节点的两侧！
        if (leftResult != nullptr && rightResult != nullptr)
        {
            return root;
        }

        // 如果左边没找到，说明 p 和 q 都在右边，那就把右边的结果继续往上报
        if (leftResult == nullptr)
        {
            return rightResult;
        }

        // 如果右边没找到，说明 p 和 q 都在左边，那就把左边的结果继续往上报
        if (rightResult == nullptr)
        {
            return leftResult;
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}