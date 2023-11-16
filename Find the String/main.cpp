//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

    void dfs(int k,string prev,unordered_set<string>& set,string &ans) {
        for(int i =0;i<k;i++) {
            string curr = prev + to_string(i);
            
            if(set.find(curr)==set.end()) {
                set.insert(curr);
                dfs(k,curr.substr(1),set,ans);
                ans.push_back(i+'0');
            }
        }
    }

    string findString(int n, int k) {
        string s(n-1,'0');
        string ans;
        unordered_set<string> set;
        dfs(k,s,set,ans);
        ans+=s;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends