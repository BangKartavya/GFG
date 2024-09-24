//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int n = s.size();
        int m = p.size();
        
        if(n < m) return "-1";
        
        vector<int> target(256,0);
        
        for(auto i: p) target[i]++;
        
        int start = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int count = 0;
        
        vector<int> window(256,0);
        
        for(int end = 0; end < n;end++) {
            char curr = s[end];
            window[curr]++;
            
            if(target[curr] != 0 && window[curr] <= target[curr]) count++;
            
            while(count == m) {
                int windowLen = end - start + 1;
                
                if(windowLen < minLen) {
                    minLen = windowLen;
                    minStart = start;
                }
                
                char startChar = s[start];
                window[startChar]--;
                
                if(target[startChar]!=0 && window[startChar] < target[startChar]) count --;
                
                start++;
            }
        }
        if(minLen == INT_MAX) return "-1";
        
        return s.substr(minStart,minLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends