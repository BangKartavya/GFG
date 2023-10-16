//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet {
    public:
        vector<int> parent,size;
        
        DisjointSet(int n) {
            parent.resize(n,0);
            size.resize(n,1);
            for(int i =0;i<n;i++) parent[i] = i;
        }
        
        
        int find_ulp(int u) {
            if(u==parent[u]) return u;
            return parent[u] = find_ulp(parent[u]);
        }
        
        int union_find(int u,int v) {
            int uP = find_ulp(u);
            int vP = find_ulp(v);
            
            if(uP==vP) return 0;
            if(size[uP]>size[vP]) {
                parent[vP] = uP;
                size[uP] += size[vP];
            }
            else {
                parent[uP] = vP;
                size[vP] += size[uP];
            }
            return 1;
        }
};

class Solution
{
public:
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        DisjointSet ds(n*n);
        int drow[] = {-1,0,0,1};
        int dcol[] = {0,-1,1,0};
        
        int maxi = 1;
        for(int i =0;i<n;i++) {
            for(int j =0;j<n;j++) {
                if(grid[i][j]==1) {
                    for(int k=0;k<4;k++) {
                        int new_row = i + drow[k];
                        int new_col = j + dcol[k];
                        
                        if(new_row>=0 && new_row<n && new_col>=0 && new_col <n && grid[new_row][new_col]) {
                            ds.union_find(i*n+j,new_row*n+new_col);
                        }
                    }
                    maxi = max(maxi,ds.size[ds.find_ulp(i*n+j)]);
                }
            }
        }
        
        for(int i =0;i<n;i++) {
            for(int j =0;j<n;j++) {
                if(grid[i][j] == 0) {
                    set<int> s;
                    for(int k=0;k<4;k++) {
                       int new_row = i + drow[k];
                       int new_col = j + dcol[k];
                       
                       if(new_row>=0 && new_row<n && new_col >=0 && new_col<n && grid[new_row][new_col]) {
                           s.insert(ds.find_ulp(new_row*n+new_col));
                       }
                    }
                    
                    int sum = 0;
                    for(auto itr:s) sum += ds.size[itr];
                    maxi = max(maxi,sum+1);
                }
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends