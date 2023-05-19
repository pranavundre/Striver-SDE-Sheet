class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> bfs, vis(V, 0);
        q.emplace(0);
        vis[0] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            bfs.emplace_back(temp);
            for(int i : adj[temp]) if(vis[i]++ == 0) q.emplace(i);
        }
        return bfs;
    }
};
