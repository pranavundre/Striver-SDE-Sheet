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
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left), height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int diff = abs(height(root->left)-height(root->right));
        if(diff>1) return false;
        if(!(isBalanced(root->right) && isBalanced(root->left))) return false;
        return true;
    }
};
