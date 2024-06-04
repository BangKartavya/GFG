//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.size();
        if(s[n-1]=='0') {
            s[n-1] = '1';
            int i =0;
            for(;i<s.size();i++) {
                if(s[i] == '1') break;
            }
            string p = s.substr(i,s.size()-i);
            return p;
        }
        else {
            s[n-1] = '0';
            int carry = 1;
            for(int i =n-2; i>=0;i--) {
                int p = s[i]-'0';
                if(p==1 && carry == 1) {
                    s[i] = '0';
                }
                else if(p==0 && carry == 1) {
                    s[i] = '1';
                    carry = 0;
                }
            }
            
            if(carry!=0) {
                s.insert(0,"1");
            }
        }
        int i =0;
        for(;i<s.size();i++) {
            if(s[i] == '1') break;
        }
        string p = s.substr(i,s.size()-i);
        return p;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends