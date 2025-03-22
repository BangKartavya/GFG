//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
        vector<int> arr;
        int n;

        vector<vector<vector<int>>> dp;

        int solve(int i, bool didLootPrevious, bool didLootFirst) {
            if(i >= n) return 0;

            if(dp[i][didLootPrevious][didLootFirst] != -1) return dp[i][didLootPrevious][didLootFirst];

            int takeZero = 0;
            int noTakeZero = 0;
            int take = 0;
            int noTake = 0;

            if(i == 0) {
                takeZero = arr[i] + solve(i + 1, true, true);
                noTakeZero = solve(i + 1, false, false);
            } else {
                if(i == n - 1 && didLootFirst) {
                }

                else if(!didLootPrevious) {
                    take = arr[i] + solve(i + 1, true, didLootFirst);
                }
            }

            noTake = solve(i + 1, false, didLootFirst);

            return dp[i][didLootPrevious][didLootFirst] = max({takeZero, noTakeZero, take, noTake});
        }

    public:
        int maxValue(vector<int>& arr) {
            this->arr = arr;
            n = arr.size();
            dp.resize(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));
            return solve(0, false, false);
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while(s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends