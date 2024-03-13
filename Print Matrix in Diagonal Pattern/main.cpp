//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int> result;
        int row = 0;
        int col = 0;
        map<int,vector<int>> diagMap;
        for(row = 0;row<mat.size();row++) {
            for(col = 0;col<mat[0].size();col++) {
                diagMap[row+col].push_back(mat[row][col]);
            }
        }
        bool revOrder = false;
        
        for(auto it: diagMap) {
            vector<int> diag = it.second;
            
            if(!revOrder) {
                reverse(diag.begin(),diag.end());
                revOrder = true;
            }
            else revOrder = false;
            
            for(auto i: diag) result.push_back(i);
        }
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends