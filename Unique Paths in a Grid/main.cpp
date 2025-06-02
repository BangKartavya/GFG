class Solution {
  private:
    vector<vector<int>> grid;
    int n;
    int m;
    vector<vector<int>> dp;
    
    int solve(int i, int j) {
        if(i == n-1 && j == m-1) return 1;
        
        if(i >= n || j >= m || grid[i][j] == 1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = solve(i,j+1) + solve(i+1,j);
    }
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        
        dp.resize(n,vector<int>(m,-1));
        
        return solve(0,0);
    }
};