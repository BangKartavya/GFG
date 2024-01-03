//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int i =0;
        int j =0;
        int f=0;
        int cnt =0;
        int ans = S.size();
        vector<int> freq(3,0);
        
        while(j<S.size()) {
            if(freq[S[j]-'0']==0) cnt++;
            freq[S[j]-'0']++;
            if(cnt==3) {
                f = 1;
                while(freq[S[i]-'0']>1) freq[S[i++]-'0']--;
                ans = min(ans,j-i+1);
            }
            j++;
            
        }
        return f?ans:-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends