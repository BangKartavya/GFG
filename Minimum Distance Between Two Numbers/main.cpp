//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        vector<int> xx;
        vector<int> yy;
        
        for(int i =0;i<n;i++) {
            if(a[i] == x) xx.push_back(i);
            if(a[i] == y) yy.push_back(i);
        }
        
        if(xx.size()==0 || yy.size()==0) return -1;
        
        int ans = INT_MAX;
        
        for(int i=0;i<xx.size();i++) {
            for(int j=0;j<yy.size();j++) {
                ans = min(abs(xx[i]-yy[j]),ans);
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends