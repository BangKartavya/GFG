//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isVal(int x,int y,int szx,int szy) {
        return x >=0 && y >=0 && x< szx && y <szy;
    }
    int findCoverage(vector<vector<int>>& matrix) {
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};
        int cvg = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++) {
            for(int j =0;j<m;j++) {
                if(matrix[i][j]==0) {
                    for(int ii =0;ii<4;ii++) {
                        int newi = i+dx[ii];
                        int newj = j+dy[ii];
                        if(isVal(newi,newj,n,m) && matrix[newi][newj]==1) cvg++;
                    }
                }
            }
        }
        return cvg;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends