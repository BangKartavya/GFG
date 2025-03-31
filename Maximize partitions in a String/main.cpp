//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:    
    int freq[26];
    int mp[26];
    
    bool isValid() {
        for(int i = 0;i<26;i++) {
            if(mp[i] != 0 && mp[i] != freq[i]) return false;
        }
        
        return true;
    }
  
  public:
    int maxPartitions(string &s) {
    
        memset(freq,0,sizeof(freq));
        memset(mp,0,sizeof(mp));
        int n = s.size();
        
        for(char& ch: s) freq[ch-'a']++;
        
        int cnt = 0;
        
        for(int i = 0;i<n;i++) {
            mp[s[i]-'a']++;
            
            if(isValid()) {
                cnt++;
                memset(mp,0,sizeof(mp));
            }
        }
        
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends