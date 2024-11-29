//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string ans;
        
        int n = s1.size();
        int m = s2.size();
        
        int i = n-1;
        int j = m-1;
        
        int carry = 0;
        
        while(i >= 0 && j >= 0) {
            int lsb1 = s1[i]-'0';
            int lsb2 = s2[j]-'0';
            
            if(carry) {
                if(lsb1 == 1 && lsb2 == 1) {
                    ans = '1' + ans;
                    carry = 1;
                }
                else if(lsb1 == 1) {
                    ans = '0' + ans;
                    carry = 1;
                }
                else if(lsb2 == 1) {
                    ans = '0' + ans;
                    carry = 1;
                }
                else {
                    ans = '1' + ans;
                    carry = 0;
                }
            }
            else {
                if(lsb1 == 1 && lsb2 == 1) {
                    ans = '0' + ans;
                    carry = 1;
                }
                else if(lsb1 == 1) {
                    ans = '1' + ans;
                    carry = 0;
                }
                else if(lsb2 == 1) {
                    ans = '1' + ans;
                    carry = 0;
                }
                else {
                    ans = '0' + ans;
                    carry = 0;
                }
            }
            i--;
            j--;
            
        }
        
        while(i >= 0) {
            char lsb1 = s1[i];
            
            if(carry) {
                if(lsb1 == '1') {
                    ans = '0' + ans;
                    carry = 1;
                } 
                else {
                    ans = '1' + ans;
                    carry = 0;
                }
            }
            else {
                ans = lsb1 + ans;
            }
            i--;
        }
        
        while(j >= 0) {
            char lsb2 = s2[j];
            
            if(carry) {
                if(lsb2 == '1') {
                    ans = '0' + ans;
                    carry = 1;
                }  
                else {
                    ans = '1' + ans;
                    carry = 0;
                }   
            }
            else {
                ans = lsb2 + ans;
            }
            j--;
        }
        if(carry) ans = '1' + ans;
        
        int cnt = 0;
        
        while(cnt < ans.size() && ans[cnt] != '1') cnt++;
        
        
        return ans.substr(cnt);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends