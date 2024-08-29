//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
 vector<vector<int>> result;
    vector<int> current;
    int n;

    void solve(int row, int ld, int rd, int col) {
        if (row == n) {
            result.push_back(current);
            return;
        }
        int available = ((1 << n) - 1) & ~(ld | rd | col);
        while (available) {
            int bit = available & -available;
            int pos = __builtin_ctz(bit) + 1;
            current[row] = pos;
            solve(row + 1, (ld | bit) << 1, (rd | bit) >> 1, col | bit);
            available -= bit;
        }
    }

public:
    vector<vector<int>> nQueen(int n) {
        this->n = n;
        current.resize(n);
        solve(0, 0, 0, 0);
        return result;   
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends