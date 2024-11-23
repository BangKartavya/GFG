//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        int getMinDiff(int k, vector<int>& arr) {
            sort(begin(arr), end(arr));

            int n = arr.size();

            if(n == 1) return 0;

            int ans = arr[n - 1] - arr[0];

            for(int i = 1; i < n; i++) {
                int maxi = max(arr[i - 1] + k, arr[n - 1] - k);
                int mini = min(arr[i] - k, arr[0] + k);

                ans = min(ans, maxi - mini);
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while(t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends