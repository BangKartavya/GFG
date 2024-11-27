//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        set<int> s;
        
        for(auto i: arr) if(i >= 0) s.insert(i);
        
        if(s.find(1) == s.end()) return 1;
        
        for(auto i: s) {
            if(s.find(i+1) == s.end()) return i+1;
        }
        
        return *(s.end()--) + 1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends