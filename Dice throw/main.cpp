class Solution {
  private:
    int m;
    int n;
    int x;
    vector<vector<int>> dp;
    
    int solve(int i, int j) { // i-> sum, j-> number of dice used
        if(j == -1 || i > x) return 0;
        if(j == 0) return i==x;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int answer = 0;
        
        for(int k = 1;k<=m;k++) {
            if(i + k <= x) {
                int ways = solve(i+k,j-1);
                answer += ways;
            }
            else break;
        }
        
        return dp[i][j] = answer;
    }
  public:
    int noOfWays(int m, int n, int x) {
        this->m = m;
        this->n = n;
        this->x = x;
        
        dp.resize(m*n+1,vector<int>(n+1,-1));
        
        return solve(0,n); 
    }
};