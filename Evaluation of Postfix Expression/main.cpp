5//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int evaluate(vector<string>& arr) {
            stack<int> stk;

            for(string& ch : arr) {
                if(ch != "+" && ch != "-" && ch != "/" && ch != "*") stk.push(stoi(ch));
                else {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();

                    if(ch == "+") stk.push(a + b);
                    else if(ch == "*") stk.push(a * b);
                    else if(ch == "-") stk.push(b - a);
                    else stk.push(b / a);
                }
            }

            return stk.top();
        }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while(t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while(ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends