class Solution {
public:
    vector <int> bottomView(Node *root) {
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
            auto it = mp.find(a);

            if(it == mp.end()) mp.insert(make_pair(a, temp));
            else it->second = temp;

            if(temp->left) q.emplace(make_pair(temp->left, a-1));
            if(temp->right) q.emplace(make_pair(temp->right, a+1));
        }
        
        for(auto p : mp) ret.emplace_back(p.second->data);
        
        return ret;
    }
};
