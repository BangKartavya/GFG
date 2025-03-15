//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<int> coins;
    int n;
    
    vector<vector<int>> dp;
    
    int solve(int i, int sum) {
        if(i < 0) return 1e9;
        if(sum == 0) return 0;
        if(sum < 0) return 1e9;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int ans = 1e9;
        
        if(coins[i] <= sum) {
            ans = min(ans,1 + solve(i,sum-coins[i]));
        }
        ans = min(ans,solve(i-1,sum));
        
        return dp[i][sum] = ans;
        
    }
  public:
    int minCoins(vector<int> &coins, int sum) {
        if(sum == 0) return 0;
        sort(begin(coins),end(coins));
        
        this->coins = coins;
        n = coins.size();
        
        dp.resize(n+1,vector<int>(sum+1,-1));
        
        return (solve(n-1,sum) >= 1e9) ? -1 : solve(n-1,sum);
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends