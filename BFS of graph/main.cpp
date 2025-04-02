//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        // Function to return Breadth First Traversal of given graph.
        vector<int> bfs(vector<vector<int>>& adj) {
            queue<int> q;
            vector<bool> vis(adj.size(), false);
            vector<int> result;
            q.push(0);
            vis[0] = true;

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                result.push_back(node);
                for(int& it : adj[node]) {
                    if(!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            return result;
        }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for(int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while(ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends