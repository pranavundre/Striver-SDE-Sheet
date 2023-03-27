
// Left and Right View of Binary Tree ---->>>


// Left View of Binary Tree

// Iterative Approach---------------------
vector<int> leftView(Node *root){
    vector<int> ret;
    if(!root) return ret;
    
    map<int, Node*> mp;
    queue<pair<Node*, int>> q;
    
    q.emplace(make_pair(root, 0));
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        
        Node* temp = p.first;
        int a = p.second;
        
        if(mp.find(a) == mp.end()) mp.insert(make_pair(a, temp));
        
        if(temp->left) q.emplace(make_pair(temp->left, a+1));
        if(temp->right) q.emplace(make_pair(temp->right, a+1));
    }
    
    for(auto p : mp) ret.emplace_back(p.second->data);
    return ret;
}

// Recursive Approach---------------------
void recursive(Node* root, int lvl, vector<int> &ret){
    if(!root) return;
    if(lvl == ret.size()) ret.emplace_back(root->data);
    recursive(root->left, lvl+1, ret);
    recursive(root->right, lvl+1, ret);
}
vector<int> leftView(Node *root){
    vector<int> ret;
    recursive(root, 0, ret);
    return ret;
}

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Right View of Binary Tree
   
// Iterative Approach---------------------
vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    if(!root) return ret;

    map<int, TreeNode*> mp;
    queue<pair<TreeNode*, int>> q;

    q.emplace(make_pair(root, 0));

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* temp = p.first;
        int a = p.second;

        mp[a] = temp;

        if(temp->left) q.emplace(make_pair(temp->left, a+1));
        if(temp->right) q.emplace(make_pair(temp->right, a+1));
    }

    for(auto p : mp) ret.emplace_back(p.second->val);
    return ret;
}

// Recursive Approach---------------------
void recursive(TreeNode* root, int lvl, vector<int> &ret){
    if(!root) return;
    if(lvl == ret.size()) ret.emplace_back(root->val);
    recursive(root->right, lvl+1, ret);
    recursive(root->left, lvl+1, ret);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    recursive(root, 0, ret);
    return ret;
}

