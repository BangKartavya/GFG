//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int commonDiff = arr[1] - arr[0];
        int s = 0;
        int e = n-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(arr[0] + commonDiff*mid < arr[mid]) {
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return arr[0] + s * commonDiff;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends