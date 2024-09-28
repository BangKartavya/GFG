//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int minimizeCost(int k, vector<int>& arr) {
            int n = arr.size();
            vector<int> dp(n, 1e9);
            dp[0] = 0;

            for(int i = 0; i < n; i++)
                for(int j = i - k; j < i; j++)
                    if(j >= 0)
                        dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
            return dp[n - 1];
        }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while(t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends