//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int largest = INT_MIN;
        int second_largest = INT_MIN;
        
        for(auto i: arr) {
            if(i > largest) {
                second_largest = largest;
                largest = i;
            }
            else if(i == largest) continue;
            
            else if(i == second_largest) continue;
        
            else if(i >= second_largest) second_largest = i;
            
        }
        
        return second_largest == INT_MIN ? -1 : second_largest;
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends