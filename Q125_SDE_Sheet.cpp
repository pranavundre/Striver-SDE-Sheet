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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir, map<int, int> &inmp){
        if(pl > pr || il > ir) return NULL;

        TreeNode* root = new TreeNode(preorder[pl]);

        int inRoot = inmp[preorder[pl]];
        int numsLeft = inRoot - il;

        root->left = build(preorder, inorder, pl+1, pl+numsLeft, il, inRoot-1, inmp);
        root->right = build(preorder, inorder, pl+numsLeft+1, pr, inRoot+1, ir, inmp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmp;

        for(int i = 0; i < inorder.size(); i++) inmp[inorder[i]] = i;

        TreeNode* node = build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, inmp);
        
        return node;
    }
};
