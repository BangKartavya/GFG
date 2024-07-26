//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        vector<int> v(26,0);
        
        int cnt = 0;
        int s = 0;
        
        for(auto i: str) {
            if(i != ' ') {
                v[i-'a']++;
                s++;
            }
        }
        
        for(auto i: v) if(i==0) cnt++;
        
        return (cnt <= k) && s >= 26;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends