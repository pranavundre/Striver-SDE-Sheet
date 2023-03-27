/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool path(TreeNode* a, int b, vector<int>& ret){
    if(!a) return false;
    ret.emplace_back(a->val);
    if(a->val == b) return true;
    if(path(a->left, b, ret) || path(a->right, b, ret)) return true;
    ret.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ret;
    path(A, B, ret);
    return ret;
}
