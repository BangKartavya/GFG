class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = INT_MIN;
        
        for(int i = 0;i<n;i++) {
            vector<int> temp(m);
            for(int j = i;j<n;j++) {
                for(int c = 0;c<m;c++) {
                    temp[c] += mat[j][c];
                }
                
                int sum = 0;
                
                for(int c = 0;c<m;c++) {
                    sum += temp[c];
                    
                    if(sum > maxi) maxi = sum;
                    if(sum < 0) sum = 0;
                }
            }
        }
        
        return maxi;
    }
};
