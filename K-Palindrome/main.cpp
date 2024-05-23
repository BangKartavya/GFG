//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // Tabulation
    int kPalindrome(string str1, int n, int k) {
        string str2 = str1;
        reverse(str2.begin(), str2.end());
        
        int dp[n + 1][n + 1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0)
                    dp[i][j] = j;
                    
                else if(j == 0)
                    dp[i][j] = i;
                    
                else if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                    
                else 
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[n][n] <= 2 * k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Endsm