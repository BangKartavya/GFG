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
            if(i >= n || sum < 0) return 0;

            if(i == 0) {
                dp[i][sum] = (sum % coins[i] == 0);
            }

            if(dp[i][sum] != -1) return dp[i][sum];

            int take = 0;
            if(coins[i] <= sum) {
                take = solve(i, sum - coins[i]);
            }
            int noTake = solve(i - 1, sum);

            return dp[i][sum] = take + noTake;
        }

    public:
        int count(vector<int>& coins, int sum) {
            sort(begin(coins), end(coins));

            this->coins = coins;
            n = coins.size();

            dp.resize(n + 1, vector<int>(sum + 1, -1));
            solve(n - 1, sum);
            return dp[n - 1][sum];
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends