//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<int> prices;
    int n;
    
    vector<vector<int>> dp;
    
    int solve(int i, int transactionCount) {
        if(i >= n) return 0;
        if(transactionCount > 4) return 0;
        
        if(dp[i][transactionCount] != -1) return dp[i][transactionCount];
        
        int buy = 0;
        int sell = 0;
        
        if(transactionCount % 2 == 0) {
            buy = -prices[i] + solve(i+1,transactionCount+1);
        }
        else {
            sell = prices[i] + solve(i+1,transactionCount+1);
        }
        
        int skip = solve(i+1,transactionCount);
        
        return dp[i][transactionCount] = max({buy,sell,skip});
    }
    
  public:
    int maxProfit(vector<int> &prices) {
        this->prices = prices;
        n = prices.size();
        dp.resize(n+1,vector<int>(5,-1));
        return solve(0,0);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends