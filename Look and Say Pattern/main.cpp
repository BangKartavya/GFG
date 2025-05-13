//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string before = countAndSay(n-1);
        
        string now;
        
        char ch = before[0];
        int cnt = 0;
        
        for(int i = 0;i<before.size();i++) {
            if(ch == before[i]) {
                cnt++;
            }
            else {
                now += to_string(cnt) + ch;
                ch = before[i];
                cnt = 1;
            }
        }
        now += to_string(cnt) + ch;
        return now;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends