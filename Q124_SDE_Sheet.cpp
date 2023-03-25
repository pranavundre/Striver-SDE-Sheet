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
    int sum(TreeNode* root, int& maxSum){
        if(!root) return 0;
        int l = sum(root->left, maxSum);
        int r = sum(root->right, maxSum);
        maxSum = max(maxSum, l+r+root->val);
        return max(0, root->val + max(l, r));
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        sum(root, maxSum);
        return maxSum;
    }
};
