class Solution {
    bool dfs(int s, int par, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[s] = 1;
        for(auto &it: adj[s])
        {
            if(!vis[it])
            {
                if(!dfs(it, s, adj, vis))return false;
            }
            else if(it!=par)return false;
        }
        return true;
    }
    
  public:
    int isTree(int n, int m, vector<vector<int>> &g) {
        vector<vector<int>> adj(n);
        for(int i = 0; i<m; i++)
        {
            if(g[i][0] == g[i][1])return 0;
            adj[g[i][0]].push_back(g[i][1]);
            adj[g[i][1]].push_back(g[i][0]);
        }
        
        vector<int> vis(n, 0);
        
        if(!dfs(0, 0, adj, vis))return 0;
        
        for(auto &it: vis)
        {
            if(it == 0)return 0;
        }
        
        return 1;
    }
};