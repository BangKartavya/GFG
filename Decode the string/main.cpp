//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        string decodedString(string& s) {
            stack<int> stkInt;
            stack<string> stkString;
            string temp;
            int n = 0;
            for(char& ch : s) {
                if(isdigit(ch)) {
                    n = n * 10 + (ch - '0');
                } else if(ch == '[') {
                    stkInt.push(n);
                    n = 0;
                    stkString.push(temp);
                    temp = "";
                } else if(ch == ']') {
                    int k = stkInt.top();
                    stkInt.pop();

                    for(int i = 0; i < k; i++) {
                        stkString.top() += temp;
                    }

                    temp = stkString.top();
                    stkString.pop();
                } else temp += ch;
            }

            return temp;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends