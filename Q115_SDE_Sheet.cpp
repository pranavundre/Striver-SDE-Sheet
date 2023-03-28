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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int left, right, maxW = 0;

        queue<pair<TreeNode*, int>> q;
        q.emplace(make_pair(root, 0));

        while(!q.empty()){
            int s = q.size();
            auto p = q.front();
            left = p.second;

            while(s--){
                p = q.front();
                right = p.second-left;
                q.pop();

                if(p.first->left) q.emplace(make_pair(p.first->left, (long long)right*2+1));
                if(p.first->right) q.emplace(make_pair(p.first->right, (long long)right*2+2));
            }
            
            left = 0;            
            maxW = max(maxW, right-left+1);
        }
        return maxW;
    }
};
