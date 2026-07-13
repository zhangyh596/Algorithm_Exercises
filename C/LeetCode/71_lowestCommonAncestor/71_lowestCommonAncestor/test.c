#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

// 自顶而下会超时
//bool isInLeft(struct TreeNode* root, struct TreeNode* target)
//{
//	if (root == NULL)
//	{
//		return false;
//	}
//
//	if (root == target)
//	{
//		return true;
//	}
//	else
//	{
//		return isInLeft(root->left, target) || isInLeft(root->right, target);
//	}
//}
//
//bool isInRight(struct TreeNode* root, struct TreeNode* target)
//{
//	if (root == NULL)
//	{
//		return false;
//	}
//
//	if (root == target)
//	{
//		return true;
//	}
//	else
//	{
//		return isInRight(root->left, target) || isInRight(root->right, target);
//	}
//}
//
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//	while (root != NULL)
//	{
//		if (root == p || root == q)
//		{
//			return root;
//		}
//
//		if ((isInLeft(root->left, p) && isInRight(root->right, q)) || (isInLeft(root->left, q) && isInRight(root->right, p)))
//		{
//			return root;
//		}
//		else if (isInLeft(root->left, p) && isInLeft(root->left, q))
//		{
//			root = root->left;
//		}
//		else if (isInRight(root->right, p) && isInRight(root->right, q))
//		{
//			root = root->right;
//		}
//	}
//	return NULL;
//}


//优化做法，自底而上
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	if (root == NULL || root == p || root == q)
	{
		return root;
	}

	//分别去左子树和右子树找
	struct TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
	struct TreeNode* right_result = lowestCommonAncestor(root->right, p, q);

	if(left_result != NULL && right_result != NULL)
	{
		return root;
	}
	else if (left_result == NULL && right_result != NULL)
	{
		return right_result;
	}
	else if (left_result != NULL && right_result == NULL)
	{
		return left_result;
	}
	else
	{
		return NULL;
	}

}