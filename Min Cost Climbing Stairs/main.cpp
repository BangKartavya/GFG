//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Back-end complete function Template for C++

class Solution {
    private:
        vector<int> cost;
        int n;

        vector<int> dp;

        int solve(int i) {
            if(i >= n) return 0;

            if(dp[i] != -1) return dp[i];

            int oneStep = cost[i] + solve(i + 1);
            int twoStep = cost[i] + solve(i + 2);

            return dp[i] = min(oneStep, twoStep);
        }

    public:
        int minCostClimbingStairs(vector<int>& cost) {
            this->cost = cost;
            n = cost.size();
            dp.resize(n + 1, -1);

            int zero = solve(0);
            dp.clear();
            dp.resize(n + 1, -1);
            int one = solve(1);

            return min(zero, one);
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while(t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while(ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends