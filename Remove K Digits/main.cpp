//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        int N = S.size() ;
        stack<char>st ;
        
        for(int i = 0 ; i < N ; i ++){
            while(!st.empty() and k and st.top() > S[i]) st.pop() , k --;
            st.push(S[i]) ;
        }
        if(st.empty()) return "0" ;
        while(k--) st.pop() ;
        string ans ;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop() ;
        }
        reverse(begin(ans),end(ans)) ;
        int i = 0 ;
        while(ans[i] == '0') i ++;
        return (i == ans.size() ? "0" : ans.substr(i)) ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends