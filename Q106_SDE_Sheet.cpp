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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return ret;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ret.emplace_back(root->val);
        return ret;
    }
};



// Iterative

// Using 2 Stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk1, stk2;
        if(root) stk1.emplace(root);
        while(!stk1.empty()){
            TreeNode* temp = stk1.top();
            stk2.emplace(temp);
            stk1.pop();
            if(temp->left) stk1.push(temp->left);
            if(temp->right) stk1.push(temp->right);
        }
        while(!stk2.empty()){
            ret.emplace_back(stk2.top()->val);
            stk2.pop();
        }
        return ret;
    }
};

// Using 1 Stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
           if(root){
               stk.emplace(root);
               root = root->left;
           }
           else{
               TreeNode* temp = stk.top()->right;
               if(temp == NULL){
                   temp = stk.top();
                   stk.pop();
                   ret.emplace_back(temp->val);
                   while(!stk.empty() && temp==stk.top()->right){
                       temp = stk.top();
                       stk.pop();
                       ret.emplace_back(temp->val);
                   }
               }
               else root = temp;
           }
        }
        return ret;
    }
}; 

