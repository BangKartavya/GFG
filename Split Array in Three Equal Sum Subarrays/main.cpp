//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
    public:
        // Function to determine if array arr can be split into three equal sum sets.
        vector<int> findSplit(vector<int>& arr) {
            int n = arr.size();

            vector<int> pre(n);
            vector<int> suf(n);

            vector<int> ans;

            pre[0] = arr[0];
            suf[n - 1] = arr[n - 1];

            for(int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + arr[i];
                suf[n - i - 1] = suf[n - i] + arr[n - i - 1];
            }

            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(pre[i] == (pre[j] - pre[i]) && (pre[n - 1] - pre[j] == pre[i])) {
                        return {i, j};
                    }
                }
            }
            if(ans.size() == 0) return {-1, -1};

            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while(test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if(result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends