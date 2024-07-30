//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        if(arr.size() == 1) return arr[0];
        
        string ans = "";
        sort(begin(arr),end(arr));
        
        string first = arr[0];
        string last = arr[arr.size()-1];
        
        
        
        int i = 0;
        
        while(first[i] == last[i]) ans+=first[i++];
        
        return ans.size() == 0 ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends