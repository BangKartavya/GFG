//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int n;
    int rec(int i,int w,int wgt[],int v[],vector<vector<int>> &dp) {
        if(i==n) return 0;
        if(w==0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        int ans = rec(i+1,w,wgt,v,dp);
        if(w>=wgt[i]) {
            ans = max(ans,rec(i+1,w-wgt[i],wgt,v,dp)+v[i]);
            ans = max(ans,rec(i,w-wgt[i],wgt,v,dp)+v[i]);
        }
        return dp[i][w]=ans;
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        n = N;
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return rec(0,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends