//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        
        sort(begin(arr),end(arr));
        
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                int sum = arr[i] + arr[j];
                int s = j+1;
                int e = n-1;
                
                while(s <= e) {
                    int mid = s + (e-s)/2;
                    
                    if(arr[mid] == sum) return true;
                    else if(arr[mid] > sum) e = mid-1;
                    else s = mid+1;
                }
            }
        }
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends