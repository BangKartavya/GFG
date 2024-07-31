//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;
        int strow = 0;
        int stcol = 0;
        int endrow = row-1;
        int endcol = col-1;
        
        int cnt = 0;
        vector<int> ans;
        
        while(cnt < total) {
            for(int i =strow;i<=endcol && cnt < total;i++) {
                ans.push_back(matrix[strow][i]);
                cnt++;
            }
            strow++;
            for(int i =strow;i<=endrow && cnt < total;i++) {
                ans.push_back(matrix[i][endcol]);
                cnt++;
            }
            endcol--;
            for(int i = endcol;i>=stcol && cnt < total; i--) {
                ans.push_back(matrix[endrow][i]);
                cnt++;
            }
            endrow--;
            for(int i =endrow;i>=strow && cnt < total; i--) {
                ans.push_back(matrix[i][stcol]);
                cnt++;
            }
            stcol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends