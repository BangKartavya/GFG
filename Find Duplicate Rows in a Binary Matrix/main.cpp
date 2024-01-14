//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        map<int,vector<int>> mp1,mp2;
        
        for(int i=0;i<M;i++) {
            // vector<int> t;
            
            // for(int j =0;j<N;j++) t.push_back(matrix[i][j]);
            // mp1[i] = t;
            // mp2[i] = t;
            
            mp1[i] = matrix[i];
            mp2[i] = matrix[i];
        }
        
        set<int> ansIndex;
        
        for(int i =0;i<mp1.size();i++) {
            for(int j =i;j<mp1.size();j++) {
                if(i==j) continue;
                else {
                    if(mp1[i]==mp2[j]) ansIndex.insert(j);
                }
            }
        }
        // set<int> s(ansIndex.begin(),ansIndex.end());
        
        vector<int> ans(ansIndex.begin(),ansIndex.end());
        
        return ans;
      
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends