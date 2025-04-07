//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<vector<int>> adj;
    vector<bool> vis;
    
    bool dfs(int node,unordered_set<int> curr) {
        vis[node] = true;
        
        for(int& it: adj[node]) {
            if(curr.find(it) != curr.end()) {
                return true;
            }
            curr.insert(it);
            if(dfs(it,curr)) return true;
            curr.erase(it);
        }
        
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        adj.resize(V);
        vis.resize(V,false);
        for(vector<int>& edge:  edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i,{})) return true;
            }
        }
        
        
        return false;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends