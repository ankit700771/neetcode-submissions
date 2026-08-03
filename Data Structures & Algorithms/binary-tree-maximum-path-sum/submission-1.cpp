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

class Solution {
public:
    int maxSum;

    int solve(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        int converge = left + right + root->val;
        int left_or_right = max(left, right) + root->val;
        int root_good = root->val;

        maxSum = max({maxSum, converge, left_or_right, root_good});

        return max(left_or_right, root_good);

    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);

        return maxSum;
    }
};
