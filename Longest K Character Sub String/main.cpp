//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    if(k>s.length()){
        return -1;
    }
    int left =0;
    int uniqueCount=0;
    int maxLen = 0;
    unordered_map<char,int> freq;
    
    for(int right = 0;right<s.length();right++) {
        if(freq.find(s[right])==freq.end()) {
            uniqueCount++;
            freq[s[right]]=1;
        }
        else{
            freq[s[right]]+=1;
        }
        
        while(uniqueCount>k) {
            freq[s[left]] -=1;
            if(freq[s[left]]==0) {
                uniqueCount --;
                freq.erase(s[left]);
            }
            left++;
        }
        maxLen = max(maxLen,right-left+1);
    }
    if(maxLen ==0) {
        return -1;
    }
    return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends