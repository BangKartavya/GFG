//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
    private:
        string s1;
        string s2;
        int n;

        vector<vector<int>> dp;

        int solve(int i, int j) {
            if(i >= n || j >= n) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            if(s1[i] == s2[j]) {
                return dp[i][j] = 1 + solve(i + 1, j + 1);
            }

            return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
        }

    public:
        int longestPalinSubseq(string& s) {
            s1 = s;
            reverse(begin(s), end(s));
            s2 = s;
            n = s.size();
            dp.resize(n + 1, vector<int>(n + 1, -1));

            return solve(0, 0);
        }
};

//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends