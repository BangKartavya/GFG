//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        int maxi = 0;
            int startIdx = -1;
            int n = s.size();

            for(int i = 0; i < n; i++) {
                int st = i;
                int e = i;

                while(st >= 0 && e < n && s[st] == s[e]) {
                    if(e - st + 1 > maxi) {
                        maxi = e - st + 1;
                        startIdx = st;
                    }
                    st--;
                    e++;
                }
            }

            for(int i = 0; i < n - 1; i++) {
                int st = i;
                int e = i + 1;

                while(st >= 0 && e < n && s[st] == s[e]) {
                    if(e - st + 1 > maxi) {
                        maxi = e - st + 1;
                        startIdx = st;
                    }
                    st--;
                    e++;
                }
            }

            return s.substr(startIdx, maxi);
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends