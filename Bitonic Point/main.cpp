//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution {
    public:
        int findMaximum(vector<int>& arr) {
            int n = arr.size();
            int s = 0;
            int e = n - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(mid > 0 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return arr[mid];

                if(mid > 0 && arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid]) s = mid + 1;

                if(mid > 0 && arr[mid] < arr[mid - 1] && arr[mid + 1] < arr[mid]) e = mid - 1;
            }

            return arr[n - 1];
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while(t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while(ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends