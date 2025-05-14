//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        int freq[26];
        int n = s.size();
        memset(freq,0,sizeof(freq));
        
        for(char& ch: s) freq[ch-'a']++;
        
        int count = 0;
        
        for(int i = 0;i<n;i++) {
            count += freq[s[i]-'a'];
            
            freq[s[i]-'a']--;
        }
        
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends