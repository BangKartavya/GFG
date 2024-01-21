//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            int total = 1<<n;
                int mini=1e9 ;
                for(int i=0;i<total;i++){
                    int curr = i ;
                    int size = edges.size() ;
                    for(auto it:edges){
                        int num1 = it.first ;
                        int num2 = it.second ;
                        num1-- ;
                        num2 -- ;
                        if(curr & (1<<num1) or curr & (1<<num2)) size-- ;
                    }
                    if(size==0){
                        mini = min(mini , __builtin_popcount(curr)) ;
                    }
                }
                return mini ;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends