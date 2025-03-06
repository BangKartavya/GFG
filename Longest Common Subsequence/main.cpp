//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
        string s1;
        string s2;

        vector<vector<int>> dp;

        int solve(int i, int j) {
            if(i >= s1.size() || j >= s2.size()) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            if(s1[i] == s2[j]) {
                return dp[i][j] = 1 + solve(i + 1, j + 1);
            }

            return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
        }

    public:
        int lcs(string& s1, string& s2) {
            this->s1 = s1;
            this->s2 = s2;
            dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));

            return solve(0, 0);
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends