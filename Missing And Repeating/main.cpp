//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n=arr.size();
       long long sn=(long long)n*(n+1)/2;
       long long square=(long long)n*(n+1)*(2*n+1)/6;
       long long orgsn=0;
       long long orgsquare=0;
       for(int i=0;i<n;i++){
           orgsn+=arr[i];
           orgsquare+=(long long )arr[i]*arr[i];
       }
       long long diff1=orgsn-sn;
       long long diff2=orgsquare-square;
       long long sumBA=diff2/diff1;
      int   B=(diff1+sumBA)/2;
       int A=sumBA-B;
       return {B,A};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends