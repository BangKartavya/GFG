//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        bool dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i =2;i<n+1;i++) {
            if((i-1>=0 && dp[i-1]==false) || (i-x>=0 && dp[i-x]==false) || (i-y>=0 && dp[i-y]==false) ) dp[i] = true;
            else dp[i] = false;
        }
        return dp[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends