class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        
        int s = 0;
        int e = n*m-1;
        
        int piv = -1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            int x = mid/m;
            int y = mid%m;
            
            int ex = e/m;
            int ey = e%m;
            
            int prev;
            int next;
            
            if(y > 0) prev = mat[x][y-1];
            else if(x > 0) prev = mat[x-1][m-1];
            else prev = INT_MAX;
            
            if(y < m-1) next = mat[x][y+1];
            else if(x < n-1) next = mat[x+1][0];
            else next = INT_MAX;
            
            if(mat[x][y] < prev && mat[x][y] < next) {
                piv = mid;
                break;
            }
            
            else if(mat[x][y] > mat[ex][ey]) {
                s = mid+1;
            }
            else e = mid-1;
        }
        
        // we got the pivot, search before the pivot, search after the pivot
        
        s = 0;
        e = piv-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            int x = mid/m;
            int y = mid%m;
            
            if(mat[x][y] == target) return true;
            else if(mat[x][y] < target) s = mid+1;
            else e = mid-1;
        }
        
        s = piv;
        e = n*m-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            int x = mid/m;
            int y = mid%m;
            
            if(mat[x][y] == target) return true;
            else if(mat[x][y] < target) s = mid+1;
            else e = mid-1;
        }
        
        return false;
        
    }
};
