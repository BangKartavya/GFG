//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    const int MOD = 1e9 + 7;
    int countgroup(vector<int>& arr) {
        int xors = 0;
        int n = arr.size();
        
        for(auto i: arr) xors^=i;
        if(xors) return 0;
        
        else return (((1ll<<n)-2)/2)%MOD;
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
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends