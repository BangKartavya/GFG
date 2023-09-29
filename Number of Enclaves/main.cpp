//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    
    void dfs(int i ,int j ,vector<vector<int>> &grid,int n,int m) {
        grid[i][j]=0;
        for(int k =0;k<4;k++) {
            int row = i+dx[k];
            int col = j+dy[k];
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1) {
                dfs(row,col,grid,n,m);
            }
        }
        return;
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int ans = 0,n = grid.size(), m =grid[0].size();
        
        for(int i =0;i<n;i++) {
            if(grid[i][0]==1) {
                dfs(i,0,grid,n,m);
            }
            if(grid[i][m-1]==1) {
                dfs(i,m-1,grid,n,m);
            }
        }
        for(int i =0;i<m;i++) {
            if(grid[0][i] == 1) {
                dfs(0,i,grid,n,m);
            }
            if(grid[n-1][i]==1) {
                dfs(n-1,i,grid,n,m);
            }
        }
        
        for(int i =1;i<n-1;i++) {
            for(int j = 1;j<m-1;j++) {
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends