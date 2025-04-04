//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(vector<int>& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        queue<pair<int,int>> q; // {node,parent}
        vector<bool> vis(V,false);
        
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                q.push({i,-1});
                vis[i] = true;
                
                while(!q.empty()) {
                    int curr = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    
                    for(int& it: adj[curr]) {
                        if(!vis[it]) {
                            vis[it] = true;
                            q.push({it,curr});
                        }
                        else {
                            if(it != parent) return true;
                        }
                    }
                }
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends