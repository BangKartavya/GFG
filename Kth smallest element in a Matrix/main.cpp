class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        int s = mat[0][0];
        int e = mat[n-1][n-1];
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            int up = 0;
            
            for(int i = 0;i<n;i++) {
                up += upper_bound(begin(mat[i]),end(mat[i]),mid) - begin(mat[i]);
            }
            
            if(up <= k-1) s = mid+1;
            else e = mid-1;
        }
        
        return s;
    }
};
