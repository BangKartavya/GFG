//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        if(str1.size()!=str2.size()) return false;
        
        unordered_map<char,char> hashmap;
        vector<int> visited(26,0);
        
        for(int idx=0;idx<str1.length();idx++) {
            if(hashmap.find(str1[idx])==hashmap.end()) {
                if(visited[str2[idx]-'a']==0) {
                    hashmap[str1[idx]]=str2[idx];
                    visited[str2[idx]-'a']=1;
                }
                else return false;
            }
            else {
                if(hashmap[str1[idx]]!=str2[idx]) return false;
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends