class Solution {
  private:
    vector<vector<int>> adj;
    vector<bool> vis;
    int maxi = 0;
    
    int dfs(int node) {
        vis[node] = true;
        
        int maxi1 = 0;
        int maxi2 = 0;
        
        for(int& it: adj[node]) {
            if(!vis[it]) {
                int cnt = dfs(it);
                
                if(cnt >= maxi1) {
                    maxi2 = maxi1;
                    maxi1 = cnt;
                }
                else if(cnt > maxi2) maxi2 = cnt;
            }
        }
        
        maxi = max(maxi,maxi1+maxi2);
        return 1  + max(maxi1,maxi2);
    }
    
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        adj.resize(V);
        vis.resize(V,false);
        
        for(vector<int>& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        return maxi;
    }
};
