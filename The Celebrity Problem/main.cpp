//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int celeb = -1;
        
        for(int i =0;i<n;i++) {
            int cnt = 0;
            for(auto x: mat[i]) {
                cnt+=x;
            }
            if(cnt==0) {
                if(celeb!=-1) return -1;
                celeb = i;
            }
        }
        for(int i =0;i<n;i++) {
            if(i == celeb) continue;
            if(mat[i][celeb] != 1) return -1;
        }
        return celeb;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends