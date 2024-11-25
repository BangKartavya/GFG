//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int prod = arr[0];
        int n = arr.size();
        int maxi = arr[0];
        int mini = arr[0];
        
        for(int i = 1;i<n;i++) {
            if(arr[i] < 0) {
                int temp = maxi;
                maxi = mini;
                mini = temp;
            }
            
            maxi = max(arr[i],arr[i]*maxi);
            mini = min(arr[i],arr[i]*mini);
            
            prod = max(prod,maxi);
        }
        
        return prod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends