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


// TC = O(N)
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        int l = height(root->left);  
        if(l==-1) return -1;
        int r = height(root->right);
        if(r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return max(l, r)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
