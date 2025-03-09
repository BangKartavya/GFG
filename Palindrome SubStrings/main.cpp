//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int countPS(string& s) {
            int cnt = 0;
            int n = s.size();

            for(int i = 0; i < n; i++) {
                int st = i;
                int e = i;

                while(st >= 0 && e < n && s[st] == s[e]) {
                    if(e - st + 1 >= 2) {
                        cnt++;
                    }
                    st--;
                    e++;
                }
            }

            for(int i = 0; i < n; i++) {
                int st = i;
                int e = i + 1;

                while(st >= 0 && e < n && s[st] == s[e]) {
                    if(e - st + 1 >= 2) {
                        cnt++;
                    }
                    st--;
                    e++;
                }
            }

            return cnt;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends