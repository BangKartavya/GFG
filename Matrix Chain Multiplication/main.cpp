//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
        vector<int> arr;
        int n;

        vector<vector<int>> dp;

        int solve(int i, int j) {
            if(i == j) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int ans = INT_MAX;

            for(int k = i; k < j; k++) {
                ans = min(ans, arr[i - 1] * arr[k] * arr[j] + solve(i, k) + solve(k + 1, j));
            }

            return dp[i][j] = ans;
        }

    public:
        int matrixMultiplication(vector<int>& arr) {
            this->arr = arr;
            n = arr.size();

            dp.resize(n, vector<int>(n, -1));

            if(n == 2) return 0;

            return solve(1, n - 1);
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while(t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while(ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl
             << "~\n";
    }

    return 0;
}

// } Driver Code Ends