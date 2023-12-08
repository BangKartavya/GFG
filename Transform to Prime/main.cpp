//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int seive[1000001];
    
    void solve() {
        for(int i =0;i<1000001;i++) seive[i] = 1;
        
        seive[0] = seive[1] = 0;
        
        for(int i =2;i*i<1000001;i++) {
            if(seive[i]) {
                for(int j = i*i;j<1000001;j+=i) seive[j] = 0;
            }
        }
    }
    
    int minNumber(int arr[],int N)
    {
        solve();
        
        int sum = 0;
        
        for(int i =0;i<N;i++) sum+=arr[i];
        
        if(seive[sum]==1) return 0;
        
        for(int i=sum;i<1000001;i++) {
            if(seive[i]==1) return i-sum;
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends