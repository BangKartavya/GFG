//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
    public:
        void pushZerosToEnd(vector<int>& arr) {
            int cnt = 0;
            int n = arr.size();

            for(auto i : arr)
                if(i == 0) cnt++;

            int idx = 0;

            for(int i = 0; i < n; i++) {
                if(arr[i] == 0) continue;

                arr[idx++] = arr[i];
            }

            for(; idx < n; idx++) {
                arr[idx] = 0;
            }

            return;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends