void changeTree(BinaryTreeNode<int>* root) {
    if(!root) return;

    int child = 0;
    child = root->left ? root->left->data+child : child;
    child = root->right ? root->right->data+child : child;

    if(child>=root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    if(root->left || root->right) root->data = tot;
}  
