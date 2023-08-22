//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here
        
        int sumRow[n],sumCol[n];
        memset(sumRow, 0, sizeof(sumRow));
        memset(sumCol, 0, sizeof(sumCol));
        
        for(int i =0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                sumRow[i]+=matrix[i][j];
                sumCol[j]+=matrix[i][j];
            }
        }
        int maxSum = 0;
        for(int i =0;i<n;i++) {
            maxSum = max(maxSum,sumRow[i]);
            maxSum = max(maxSum,sumCol[i]);
        }
        
        int operation = 0;
        int i = 0;
        int j =0;
        
        while(i<n && j<n){

            int diff = min(maxSum-sumRow[i],maxSum-sumCol[j]);
            
            matrix[i][j] += diff;
            sumRow[i] +=diff;
            sumCol[j] += diff;
            operation+=diff;
            
            if(sumRow[i] == maxSum) {
                i++;
            }
            if(sumCol[j] == maxSum) {
                j++;
            }
            

        }
        return operation;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends