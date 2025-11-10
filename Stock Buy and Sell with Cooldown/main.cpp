class Solution {
  private:
    vector<int> arr;
    int n;
    
    vector<vector<int>> dp;
    
    int solve(int i, bool buy) {
        if(i >= n) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int take = 0;
        
        if(buy) {
            take = -arr[i] + solve(i+1,!buy);
        }
        else take = arr[i] + solve(i+2,!buy);
        
        int noTake = solve(i+1,buy);
        
        return dp[i][buy] = max(take,noTake);
    }
  public:
    int maxProfit(vector<int>& arr) {
        this->arr = arr;
        n = arr.size();
        dp.resize(n,vector<int>(2,-1));
        return solve(0,true);
    }
};