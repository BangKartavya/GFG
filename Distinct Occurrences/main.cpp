//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod = 1e9+7;
    int helper(string s,string t,int i,int j,vector<vector<int>>& dp) {
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = (helper(s,t,i-1,j-1,dp)%mod+helper(s,t,i-1,j,dp)%mod)%mod;
        
        return dp[i][j] = helper(s,t,i-1,j,dp)%mod;
    }
    int subsequenceCount(string s, string t)
    {
      vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
      
      return helper(s,t,s.size()-1,t.size()-1,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends