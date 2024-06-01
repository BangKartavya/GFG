//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        set<char> even = {'b','d','f','h','j','l','n','p','r','t','v','x','z'};
        set<char> odd = {'a','c','e','g','i','k','m','o','q','s','u','w','y'};
        map<char,int> mp;
        int x = 0;
        int y = 0;
        for(auto i: s) {
            mp[i]++;
        }
        
        for(auto it: mp) {
            if(even.find(it.first)!=even.end() && it.second%2==0) x++;
            else if(odd.find(it.first)!=odd.end() && it.second%2!=0) y++;
            else continue;
        }
        return (x+y)%2==0 ? "EVEN" : "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends