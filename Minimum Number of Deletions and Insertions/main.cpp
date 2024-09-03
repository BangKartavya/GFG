//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    long long n = str1.length();
	    long long m = str2.length();
	    
	    vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
	    for(long long i = n;i>=0;i--) {
    	    for(long long j = m; j>=0;j--) {
    	        if(i == n && j == m) dp[i][j] = 0;
    	        else if(i == n) dp[i][j] = m-j;
    	        else if(j == m) dp[i][j] = n-i;
    	        else if(str1[i] == str2[j]) dp[i][j] = dp[i+1][j+1];
    	        else {
    	            long long op1 = 1 + dp[i+1][j];
    	            long long op2 = 1 + dp[i][j+1];
    	            dp[i][j] = min(op1,op2);
    	        }
    	    }
	    }
	    return dp[0][0];
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends