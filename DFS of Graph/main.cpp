//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
        vector<bool> vis;
        vector<int> result;
        vector<vector<int>> adj;
        void dfs(int i) {
            for(int& it : adj[i]) {
                if(!vis[it]) {
                    vis[it] = true;
                    result.push_back(it);
                    dfs(it);
                }
            }
        }

    public:
        vector<int> dfs(vector<vector<int>>& adj) {
            int n = adj.size();
            vis.resize(n, false);
            this->adj = adj;

            vis[0] = true;
            result.push_back(0);
            dfs(0);

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
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

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
        vector<int> ans = obj.dfs(adj);
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends