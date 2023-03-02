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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return ret;
        inorderTraversal(root->left);
        ret.emplace_back(root->val);
        inorderTraversal(root->right);
        return ret;
    }
};


// Iterative

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        TreeNode* temp = root;
        while(true){
            if(temp){
                stk.emplace(temp);
                temp = temp->left;
            }
            else{
                if(stk.empty()) break;
                temp = stk.top();
                stk.pop();
                ret.emplace_back(temp->val);
                temp = temp->right;
            }
        }
        return ret;
    }
};
