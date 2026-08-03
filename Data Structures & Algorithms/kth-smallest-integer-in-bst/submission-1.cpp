/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /**
    Thinks to remember-
        -- for BFS in Tree we have
            -Inorder
            -preOrder
            -postOrder

        -- the inorder traversal give the sorted value in BST

        so think of like how to use inorder properties to solve this question
 */

class Solution {
public:

    void solve(TreeNode* root, int &k, int &ans) {
        if(root == NULL) return;

        solve(root->left, k, ans);
        k--;
        if(k == 0) ans = root->val;
        solve(root->right, k, ans);

        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};
