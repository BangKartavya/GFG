//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


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

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends