//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        int n = sentence.size();
        
        long long ans=-1;
        int i=0;
        while(i<n){
            long long sen=0;
            bool flag=true;
            while(sentence[i]-'0'>=0 && sentence[i]-'0'<=9){
                if(sentence[i]-'0'==9)
                    flag=false;
                sen=sen*10+(sentence[i]-'0');
                i++;
            }
            ans = (flag && sen!=0) ? max(ans,sen):ans;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends