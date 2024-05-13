//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>>&subgraph,int i,vector<vector<int>>&graph,vector<int>&vis,int &sz){
        vis[i]=1;
        sz++;
        for(auto child : graph[i]){
            subgraph[i].push_back(child);
            if(vis[child]==0){
                dfs(subgraph,child,graph,vis,sz);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<vector<int>>graph(v+1);
        for(int i=0;i<e;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;i++){
            if(vis[i]==0){
                vector<vector<int>>subgraph(v+1);
                int sz = 0;
                dfs(subgraph,i,graph,vis,sz);
                bool f = true;
                for(int i=0;i<subgraph.size();i++){
                    if(subgraph[i].size() > 0 and  subgraph[i].size() < sz-1){
                        f = false;
                        break;
                    }
                }
                if(f){
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends