//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool isPal(string c) {
        int n = c.size();
        
        for(int i = 0;i<n/2;i++) {
            if(c[i] != c[n-i-1]) return false;
        }
        
        return true;
    }
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(n != m) return false;
        
        if(s1 == s2) return true;
        
        int freq[26];
        memset(freq,0,sizeof(freq));
        
        for(int i = 0;i<n;i++) {
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        
        for(int i = 0;i<26;i++) if(freq[i] != 0) return false;
        
        
        string c = s1 + s1;
        
        if(c.find(s2) != string::npos) return true;
        
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends