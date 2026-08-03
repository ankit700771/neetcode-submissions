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
    point to be remember -

    --- the property of BST is the left subtree is smaller then rootnode and right subtree is larger then the root
    
    --- if you understand this then you notice something
        
        -- the left subtree hold value is min = infinity and max value should be the root value
        -- right subtree hold value is min = root value and max value should be infinity

    this is the point that need to consider for solving this question 
 */

class Solution {
public:

    bool solve(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == NULL) {
            return true;
        }

        if(min != NULL && root->val <= min->val) {
            return false;
        }

        if(max != NULL && root->val >= max->val) {
            return false;
        }

        return solve(root->left, min, root) && solve(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
};
