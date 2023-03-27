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
    queue<TreeNode*> q;
    void level(vector<vector<int>> &ret){
        if(q.empty()) return;
        vector<int> temp;
        int i = q.size();
        while(i-- > 0){
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            temp.emplace_back(q.front()->val);
            q.pop();
        }
        ret.emplace_back(temp);
        level(ret);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root) q.push(root);
        level(ret);
        return ret;
    }
};
