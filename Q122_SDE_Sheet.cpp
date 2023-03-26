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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> t;
        stack<TreeNode*> stk1, stk2;
        if(root) stk1.emplace(root);
        int lvl = 0;
        while(!stk1.empty() || !stk2.empty()){
            TreeNode* temp;
            if(lvl%2==0)
                while(!stk1.empty()){
                    temp = stk1.top();
                    stk1.pop();
                    t.push_back(temp->val);
                    if(temp->left != NULL) stk2.emplace(temp->left);
                    if(temp->right != NULL) stk2.emplace(temp->right);
                }
            else
                while(!stk2.empty()){
                    temp = stk2.top();
                    stk2.pop();
                    t.push_back(temp->val);
                    if(temp->right != NULL) stk1.emplace(temp->right);
                    if(temp->left != NULL) stk1.emplace(temp->left);
                }
            lvl++;
            ret.emplace_back(t);
            t.clear();
        }
        return ret;
    }
};
