class Solution {
  public:
    int bfs(int &V, vector<set<int>> &g, int src, int dst) {
        vector<int> dist(V, 1e9);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(auto &x : g[curr]) {
                if(dist[x] > 1 + dist[curr]) {
                    dist[x] = 1 + dist[curr];
                    q.push(x);
                }
            }
        }
        
        return dist[dst] + 1;
    }
  
    int shortCycle(int V, vector<vector<int>>& e) {
        vector<set<int>> g(V);

        for(auto &x : e) {
            g[x[0]].insert(x[1]);
            g[x[1]].insert(x[0]);
        }
        
        int ans = 1e9;
        for(auto &x : e) {
            int u = x[0];
            int v = x[1];
            g[u].erase(v);
            g[v].erase(u);
            
            ans = min(ans, bfs(V, g, u, v));
        }

        return ans == 1e9 ? -1 : ans;
    }
};
