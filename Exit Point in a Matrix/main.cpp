//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;
        int dir = 0;
        vector<vector<int>> pos = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(true) {
            if(matrix[i][j]==1) {
                matrix[i][j]=0;
                dir++;
                dir%=4;
            }
            else {
                if((i==n-1 && dir==1) || (j==m-1 && dir==0) || (j==0 && dir==2) || (i==0 && dir==3)) break;
                i+=pos[dir][0];
                j+=pos[dir][1];
            }
        }
        return {i,j};
        
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
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends