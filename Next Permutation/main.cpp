//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        
        int idx = -1;
        int n = arr.size();
        
        for(int i = n-1;i>0;i--) {
            if(arr[i-1] < arr[i]) {
                idx = i-1;
                break;
            }
        }
        if(idx == -1) {
            reverse(begin(arr),end(arr));
            return;
        }
        
        for(int i = n-1;i>idx;i--) {
            if(arr[i] > arr[idx]) {
                swap(arr[i],arr[idx]);
                break;
            }
        }
        
        reverse(begin(arr)+idx+1,end(arr));
        return;
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends