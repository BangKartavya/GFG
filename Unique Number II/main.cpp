//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
    int xor_all = 0;
    for (int num : arr)
        xor_all ^= num;
    
    int rightmost_set_bit = xor_all & -xor_all;
    int x = 0, y = 0;
    
    for (int num : arr) {
        if (num & rightmost_set_bit)
            x ^= num;
        else
            y ^= num;
    }

    if (x < y)
        return {x, y};
    else
        return {y, x};
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends