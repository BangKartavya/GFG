//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0;
        int n = prices.size();
        
        int b = 0;
        int s = 0;
        
        for(int i = 1;i<n;i++) {
            if(prices[i] < prices[b]) {
                b = i;
                s = i;
            }
            else {
                s++;
                profit = max(prices[s]-prices[b],profit);
            }
        }
        
        
        return profit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends