//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    long long int f(int ind,vector<int>& pnt,long long int n,vector<vector<long long int>>& dp) {
        if(ind==0) return n%pnt[0]==0;
        if(dp[ind][n]!=-1) return dp[ind][n];
        long long int notTake = f(ind-1,pnt,n,dp);
        long long int take = 0;
        if(pnt[ind]<=n) take = f(ind,pnt,n-pnt[ind],dp);
        
        return dp[ind][n] = take+notTake;
    }
    
    long long int count(long long int n)
    {
        vector<int> pnt = {3,5,10};
        vector<vector<long long int>> dp(3,vector<long long int>(n+1,-1));
        long long int ans = f(2,pnt,n,dp);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends