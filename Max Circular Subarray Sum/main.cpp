//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
    public:
        // arr: input array
        // Function to find maximum circular subarray sum.
        int circularSubarraySum(vector<int>& arr) {
            int max_sum = 0;
            int min_sum = 0;
            int total_sum = 0;
            int sum1 = 0;
            int sum2 = 0;

            for(auto i : arr) {
                sum1 += i;
                total_sum += i;
                max_sum = max(max_sum, sum1);

                if(sum1 < 0) sum1 = 0;
            }

            for(auto i : arr) {
                sum2 += i;
                min_sum = min(min_sum, sum2);

                if(sum2 > 0) sum2 = 0;
            }

            if(max_sum < 0) return max_sum;

            return max(max_sum, total_sum - min_sum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends