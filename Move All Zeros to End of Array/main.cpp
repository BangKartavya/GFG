//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int zeros = 0;
	    
	    vector<int> vp;
	    
	    for(int i =0;i<n;i++) {
	        if(arr[i]==0) zeros++;
	        else vp.push_back(arr[i]);
	        
	    }
	    
	    for(int i =0;i<zeros;i++) {
	        vp.push_back(0);
	    }
	    
	    for(int i =0;i<n;i++) {
	        arr[i] = vp[i];
	    }
	    
	    
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends