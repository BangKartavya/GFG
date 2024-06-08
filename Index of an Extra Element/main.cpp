//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int findExtra(int n, int arr1[], int arr2[]) {
        int s = 0;
        int e = n-1;

        while(s<=e) {
            int mid = s + (e-s)/2;
            if(mid < n && arr1[mid]==arr2[mid]) s = mid+1;
            else {
                if(mid==0) return mid;
                if(arr1[mid]!= arr2[mid-1]) return mid;
                e = mid-1;
            }
            
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends