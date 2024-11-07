//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string rep = s1;
        int reps= 1;
        
        while(rep.size() < s2.size()) {
            reps++;
            rep += s1;
        }
        
        if(rep.find(s2) != -1) return reps;
        
        rep+=s1;
        reps++;
        
        if(rep.find(s2)!= -1) return reps;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends