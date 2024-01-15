//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int helper(int curr, int totalrem, vector<int> &cost, vector<vector<int>> &dp)
    {
        if (curr == cost.size())
            return 0;
        if (totalrem < 0)
            return 0;
        if (dp[curr][totalrem] != -1)
            return dp[curr][totalrem];
        int npick = helper(curr + 1, totalrem, cost, dp) + 0;
        int pick = 0;
        if (cost[curr] <= totalrem)
        {
            pick = helper(curr + 1, (totalrem - cost[curr] + (cost[curr] * 9) / 10), cost, dp) + 1;
        }
        return dp[curr][totalrem] = max(pick, npick);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        // Code Here
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
        return helper(0, total, cost, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends