//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        vector<string> s;
        string temp;
        for(auto i: str) {
            if(i == '.') {
                s.push_back(temp);
                temp = "";
            }
            else temp += i;
        }
        s.push_back(temp);
        
        string ans;
        
        for(int i = s.size() - 1;i>=0 ;i--) {
            ans += s[i];
            if(i != 0) ans += '.';
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends