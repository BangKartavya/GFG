//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        
        if(n==0) {
            return {-1};
        }
        
        vector<int> answer;
        
        sort(arr,arr+n);
        
        for(int i =0;i<n-1;i++) {
            if(arr[i]==arr[i+1]) {
                answer.push_back(arr[i]);
            }
        }
        if(answer.size()==0) return {-1};
        
        sort(answer.begin(),answer.end());
        
        set<int> s(answer.begin(),answer.end());
        
        vector<int> ans(s.begin(),s.end());
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends