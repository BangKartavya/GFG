//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int bfs(vector<vector<int>> adj, int V) {
        queue<int> q;
        vector<int> vis(V,false);
        
        int cnt = 0;
        
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                cnt++;
                q.push(i);
                vis[i] = true;
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for(int& it: adj[node]) {
                        if(!vis[it]) {
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj1(V);
        vector<vector<int>> adj2(V);
        
        for(vector<int>& edge: edges) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
            
            if((edge[0] == c && edge[1] == d) || (edge[1] == c && edge[0] == d)) {
                continue;
            }
                adj2[edge[0]].push_back(edge[1]);
                adj2[edge[1]].push_back(edge[0]);
        }
        /*
        for(int i = 0;i<V;i++) {
            cout << i << " : ";
            for(int& it: adj2[i]) {
                cout << it << " ";
            }
            cout << endl;
        }
        */
        int c1 = bfs(adj1,V);
        int c2 = bfs(adj2,V);
        
        
        return c1 != c2;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends