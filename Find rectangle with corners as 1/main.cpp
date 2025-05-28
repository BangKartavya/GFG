class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int,vector<int>> xList;
        unordered_map<int,vector<int>> yList;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j] == 1) {
                    xList[i].push_back(j);
                    yList[j].push_back(i);
                }
            }
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j] == 1) {
                    // search right
                    for(int& x: xList[i]) {
                        if(x > j) {
                            // search down from right corner
                            for(int& z: yList[x]) {
                                if(z > i) {
                                    // search down from left corner
                                    for(int& y: yList[j]) {
                                        if(z == y) return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};