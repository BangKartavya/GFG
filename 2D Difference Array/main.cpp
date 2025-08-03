class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> diff(n+1,vector<int>(m+1));
        
        for(vector<int> operation: opr) {
            int val = operation[0];
            
            int r1 = operation[1];
            int c1 = operation[2];
            int r2 = operation[3];
            int c2 = operation[4];
            
            diff[r1][c1] += val;
            diff[r2+1][c1] -= val;
            diff[r1][c2+1] -= val;
            diff[r2+1][c2+1] += val;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }
    
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }
       
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                mat[i][j] += diff[i][j];
            }
        }
        
        return mat;
    }
};