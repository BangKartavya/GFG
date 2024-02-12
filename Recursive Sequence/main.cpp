//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    long long sequence(int n){
        long long int ans = 0;
        if(n==1) return 1;
        
        int cnt = 1;
        for(int i = 1;i<=n;i++) {
            long long int temp = 1;
            for(int j = 1;j<=i;j++) {
                temp = ((temp)*(cnt))%mod;
                cnt++;
            }
            ans = (ans+temp)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends