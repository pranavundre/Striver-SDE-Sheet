#include <bits/stdc++.h> 
using namespace std;

/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int>* root){
    if(!root->left && !root->right) return true;
    return false;
}

void addLeaves(TreeNode<int>* root, vector<int>& ret){
    if(isLeaf(root)){
        ret.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, ret);
    if(root->right) addLeaves(root->right, ret);
}

void addLeftBoundary(TreeNode<int>* root, vector<int>& ret){
    TreeNode<int>* temp = root->left;
    while(temp){
        if(!isLeaf(temp)) ret.emplace_back(temp->data);
        if(temp->left) temp = temp->left;
        else temp = temp->right;
    }
}

void addRightBoundary(TreeNode<int>* root, vector<int>& ret){
    if(isLeaf(root)) return;
    if (root->right) addRightBoundary(root->right, ret);
    else addRightBoundary(root->left, ret);
    ret.emplace_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ret;
    if(!root) return ret;
    if(!isLeaf(root)) ret.emplace_back(root->data);
    addLeftBoundary(root, ret);
    addLeaves(root, ret);
    if(root->right) addRightBoundary(root->right, ret);
    return ret;
}
