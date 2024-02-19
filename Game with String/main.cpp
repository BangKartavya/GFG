//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    int minValue(string s, int k){
        
        unordered_map<char,int> mp;
        
        for(auto i: s) mp[i]++;
        
        for(int i =0;i<k;i++) {
            char c = '\0';
            int max = INT_MIN;
            for(auto it : mp) {
                if(it.second>max) {
                    max = it.second;
                    c = it.first;
                }
            }
            mp[c]--;
        }
        int res = 0;
        
        for(auto i: s) {
            res += pow(mp[i],2);
            mp[i] = 0;
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends