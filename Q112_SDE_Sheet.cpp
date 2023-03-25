#include <bits/stdc++.h> 
using namespace std;

/************************************************************
    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ret(3);
  
    stack<pair<BinaryTreeNode<int>*, int>> stk;
  
    stk.emplace(make_pair(root, 1));
    if(root==NULL) return ret;
  
    while(!stk.empty()){
      
        if(stk.top().second == 1){
            ret[1].emplace_back(stk.top().first->data);
            stk.top().second++;
            if(stk.top().first->left)
              stk.emplace(make_pair(stk.top().first->left, 1));
        }
      
        else if(stk.top().second == 2){
            ret[0].emplace_back(stk.top().first->data);
            stk.top().second++;
            if(stk.top().first->right)
              stk.emplace(make_pair(stk.top().first->right, 1));
        }
      
        else{
            ret[2].emplace_back(stk.top().first->data);
            stk.pop();
        }
    }
  
    return ret;
}
