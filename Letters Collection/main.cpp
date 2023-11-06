//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> qv[])
    {
        int ax[] = {0, 0, 1, -1, -1, -1, 1, 1};
        int by[] = {1, -1, 0, 0, -1, 1, -1, 1};
        int ax1[] = {-2, -2, -2, -2, -2, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1};
        int by1[] = {-2, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2};
        vector<int> ans;
        for (int k = 0; k < q; k++) {
            int sum = 0;
            if (qv[k][0] == 1) {
                for (int i = 0; i < 8; i++) {
                    int x = qv[k][1] + ax[i];
                    int y = qv[k][2] + by[i];
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        sum += mat[x][y];
                    }
                }
            } else {
                for (int i = 0; i < 16; i++) {
                    int x = qv[k][1] + ax1[i];
                    int y = qv[k][2] + by1[i];
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        sum += mat[x][y];
                    }
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends