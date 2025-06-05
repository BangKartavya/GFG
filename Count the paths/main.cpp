class Solution {
    private:
        vector<vector<int>> adj;
        int dest;

        vector<int> dp;

        int dfs(int node) {
            if(node == dest) return 1;

            if(dp[node] != -1) return dp[node];

            int ways = 0;
            for(int& it : adj[node])
                ways += dfs(it);
            return dp[node] = ways;
        }

    public:
        int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
            adj.resize(V);

            for(vector<int>& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
            }

            dp.resize(V, -1);

            this->dest = dest;

            return dfs(src);
        }
};