//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     int countMin(string str){
        //lps
        vector<vector<int>> dp(501,vector<int>(501,-1));
        int n=str.size();
        int lp =lps(str,n-1,0,n,dp);
        return n -lp;
    }
    int lps(string &str,int i,int j,int n,vector<vector<int>> &dp){
        if(i == -1 || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int tk =0,skp =0;
        if(str[i] == str[j]){
            tk =1 + lps(str,i -1,j +1,n,dp);
        }
        skp =max(lps(str,i -1,j,n,dp),lps(str,i,j +1,n,dp));
        return dp[i][j] =max(tk,skp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends