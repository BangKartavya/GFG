//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(int arr[],int n,int req,int k) {
        int sum = 0;
        int count = 1;
        for(int i =0;i<n;i++) {
            if(sum+arr[i]<=req) sum+=arr[i];
            else {
                sum = arr[i];
                count++;
            }
        }
        return count<=k;
    }
    int splitArray(int arr[] ,int N, int K) {
        int totalsum = 0;
        int maxi = INT_MIN;
        for(int i =0;i<N;i++) {
            totalsum+=arr[i];
            maxi = max(maxi,arr[i]);
        }
        
        int s = maxi;
        int e = totalsum;
        int ans = INT_MAX;
        
        while(s<=e) {
            int mid = s + (e-s)/2;
            
            if(isValid(arr,N,mid,K)) {
                ans = min(ans,mid);
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends