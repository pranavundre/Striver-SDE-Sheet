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
 
// Recursive

class Solution {
public:
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return ret;
        ret.emplace_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ret;
    }
};


// Iterative

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        if(root) stk.emplace(root);
        while(!stk.empty()){
            TreeNode* temp = stk.top();
            stk.pop();
            ret.emplace_back(temp->val);
            if(temp->right) stk.emplace(temp->right);
            if(temp->left) stk.emplace(temp->left);
        }
        return ret;
    }
};
