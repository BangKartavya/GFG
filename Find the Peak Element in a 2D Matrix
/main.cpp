#include <climits>
#include <vector>

class Solution {
  public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) {
        int n = size(mat);
        int m = size(mat[0]);

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                int left = INT_MIN;
                int right = INT_MIN;
                int up = INT_MIN;
                int down = INT_MIN;

                if(j-1 >= 0) left = mat[i][j-1];
                if(j+1 < m) right = mat[i][j+1];
                if(i-1 >= 0) up = mat[i-1][j];
                if(i+1 < n) down = mat[i+1][j];

                if(mat[i][j] >= left && mat[i][j] >= right && mat[i][j] >= up && mat[i][j] >= down) return {i,j};
            }
        }

        return {-1,-1};

    }
};
