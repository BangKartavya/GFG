//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        vector<int> prev(m+1,0);
        int res = 0;
        
        for(int i = 1;i<=n;i++) {
            vector<int> curr(m+1,0);
            for(int j = 1;j<=m;j++) {
                if(mat[i-1][j-1]) {
                    curr[j] = min({prev[j-1],prev[j],curr[j-1]})+1;
                }
                res = max(res,curr[j]);
            }
            prev = curr;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends