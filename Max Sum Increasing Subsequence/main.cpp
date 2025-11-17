class Solution {
  private:
    vector<int> arr;
    int n;
    vector<vector<int>> dp;
    
    int solve(int i, int lastIdx) {
        if(i >= n) return 0;
        
        if(dp[i][lastIdx+1] != -1) return dp[i][lastIdx+1];
        
        int take = 0;
        
        if(lastIdx == -1 || arr[i] > arr[lastIdx]) {
            take = arr[i] + solve(i+1,i);
        }
        
        int noTake = solve(i+1,lastIdx);
        
        return dp[i][lastIdx+1] = max(take,noTake);
    }
    
  public:
    int maxSumIS(vector<int>& arr) {
        this->arr = arr;
        n = arr.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(0,-1);
    }
};