//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s<=e) {
            int mid = s + (e-s)/2;
            
            if(mid+1 == n) return arr[mid];
            
            if(arr[mid]>arr[mid-1] && arr[mid]> arr[mid+1]) {
                return arr[mid];
            }
            if(arr[mid]>arr[mid-1] && arr[mid]< arr[mid+1]) {
                s = mid+1;
            }
            if(arr[mid]>arr[mid+1] && arr[mid] < arr[mid-1]) {
                e = mid-1;
            }
            
        }
        return -1;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends