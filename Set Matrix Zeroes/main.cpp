//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_set<int> r;
        unordered_set<int> c;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        
        for(auto i: r) {
            for(int j = 0;j<m;j++) {
                mat[i][j] = 0;
            }
        }
        
        for(auto j: c) {
            for(int i = 0;i<n;i++) {
                mat[i][j] = 0;
            }
        }
        
        return;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends