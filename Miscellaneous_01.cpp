/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        if(root) q.emplace(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
        
            if(temp->left){
                parent[temp->left] = temp;
                q.emplace(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                q.emplace(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int dist = 0;

        while(!q.empty() && dist++ < k){
            int s = q.size();

            for(int i = 0; i<s; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && !visited[temp->left]){
                    q.emplace(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.emplace(temp->right);
                    visited[temp->right] = true;
                }
                if(parent[temp] && !visited[parent[temp]]){
                    q.emplace(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }
        vector<int> ret;
        while(!q.empty()){
            ret.emplace_back(q.front()->val);
            q.pop();
        }

        return ret;
    }
};
