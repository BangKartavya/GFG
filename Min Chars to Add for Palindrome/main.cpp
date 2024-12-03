//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& str) {
        // Write your code here
        int n = str.size();
        string copy=str;
        reverse(copy.begin(),copy.end());
        str+=copy;
        int lps[2*n];
        lps[0]=0;
        int i=1;
        int j =0;
        while(i<2*n) {
            if(str[i]==str[j]){
                 
                lps[i]=j+1;
                i++;
                j++;
            }
            else {
                if(j-1>0) {
                    j=lps[j-1];
                }
                else {
                     lps[i]=0;
                     i++;
                 }
             }
         }
         
        return (n)-lps[2*n-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends