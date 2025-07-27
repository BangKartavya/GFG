class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(const int& i: rows) {
            for(int j = 0;j<m;j++) {
                mat[i][j] = 0;
            }
        }
        
        for(const int& j: cols) {
            for(int i = 0;i<n;i++) {
                mat[i][j] = 0;
            }
        }
    }
};