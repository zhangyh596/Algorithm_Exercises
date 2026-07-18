#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;

        if (root == nullptr)
        {
            return ret;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> currentLevel;

            // 开始处理当前层的节点（有几个就循环几次）
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }
            ret.push_back(currentLevel);
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main()
{
    return 0;
}