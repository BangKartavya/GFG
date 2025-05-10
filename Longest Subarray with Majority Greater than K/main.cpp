//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        
       const int n = arr.size();
        std::vector<int> m(n + 2, 1e9);
        m[0] = -1;

        int ans = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > k) {
                ++b;
            }
            else {
                --b;
            }
            
            if (b > 0) {
                ans = i + 1;
            }
            else {
                m[-b] = std::min(m[-b], i);
                ans = std::max(ans, i - m[-b + 1]);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends