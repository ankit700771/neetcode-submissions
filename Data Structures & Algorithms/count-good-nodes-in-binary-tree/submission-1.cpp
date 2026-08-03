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

    void solve(TreeNode* root, int maxVal, int &count) {
        if(root == NULL) {
            return;
        }

        if(root->val >= maxVal) {
            count++;
        }

        maxVal = max(maxVal, root->val); // here the we do not paas maxval as a refernce becouse in each path we get diffrent max element if we paas refernce then we have problem

        solve(root->left, maxVal, count);
        solve(root->right, maxVal, count);

        return;
    }

    int goodNodes(TreeNode* root) {
        int maxVal = INT_MIN;
        int count = 0;

        solve(root, maxVal, count);

        return count;

    }
};
