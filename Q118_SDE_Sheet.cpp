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
 
// TC = O(N^2)
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        int l = height(root->left)+1;
        int r = height(root->right)+1;
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        return max(height(root->left)+height(root->right), max(diameterOfBinaryTree(root->right), diameterOfBinaryTree(root->left)));
    }
};


// TC = O(N)
class Solution {
public:
    int height(TreeNode* root, int& diameter){
        if(!root) return 0;
        int l = height(root->left, diameter);
        int r = height(root->right, diameter);
        diameter = max(l+r, diameter);
        return max(l, r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};
