//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define pii pair<int,pair<int,int>>
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> par(n+1);
        for(int i=0;i<=n;i++)par[i]=i;
       vector<vector<int>> g[n+1];
       for(auto i:edges) {
           g[i[0]].push_back({i[1],i[2]});
           g[i[1]].push_back({i[0],i[2]});
       }
      priority_queue<pii, vector<pii>, greater<pii> >q;
      q.push({0,{1,0}});
      while(q.size()) {
          auto f=q.top();
          q.pop();
          int w=f.first;
          int u=f.second.first, p=f.second.second;
          if(par[u]!=u) continue;
          par[u]=p;
          if(u==n) {
              vector<int> ans={w};
              while(u) {
                  ans.push_back(u);
                  u=par[u];
              }
              return ans;
          }
          for(auto i:g[u]) 
              if(i[0]==par[i[0]]) q.push({w+i[1],{i[0],u}});
              
      }
        return {-1};
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends