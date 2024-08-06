//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        vector<string> nums;
        string temp;
        int dot_cnt = 0;
        for(auto i: str) {
            if(i == '.') {
                dot_cnt++;
                if(temp != "") {
                    if(stoi(temp) > 255) return false;
                    nums.push_back(temp);
                    temp = "";
                }
            }
            else temp += i;
        }
        if(temp != "") {
            if(stoi(temp) > 255) return false;
            else nums.push_back(temp);
        }
        
        if(nums.size() != 4) return false;
        
        if(dot_cnt != nums.size() - 1) return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends