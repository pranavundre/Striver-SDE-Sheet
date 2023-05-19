class Solution {
  public:
    void traverse(int &V, vector<int> adj[], vector<int> &vis, vector<int> &dfs, int index){
        for(int i : adj[index]){
            if(vis[i]++ == 0){
                dfs.emplace_back(i);
                traverse(V, adj, vis, dfs, i);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), dfs;
        dfs.emplace_back(0);
        vis[0] = 1;
        traverse(V, adj, vis, dfs, 0);
        return dfs;
    }
};
