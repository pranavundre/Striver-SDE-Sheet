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
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int pl, int pr, int il, int ir, map<int, int> &inmp){
        if(pl > pr || il > ir) return NULL;

        TreeNode* root = new TreeNode(postorder[pr]);

        int inRoot = inmp[postorder[pr]];
        int numsRight = ir - inRoot;

        root->left = build(postorder, inorder, pl, pr - numsRight - 1, il, inRoot - 1, inmp);
        root->right = build(postorder, inorder, pr - numsRight, pr - 1, inRoot + 1, ir, inmp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inmp;

        for(int i = 0; i < inorder.size(); i++) inmp[inorder[i]] = i;

        TreeNode* node = build(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1, inmp);
        
        return node;
    }
};
