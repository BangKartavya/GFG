class Solution {
  private:
    vector<vector<int>> result;
    int n;
    int k;
    
    void solve(int i, int rem, int currSum,vector<int> curr) {
        if(currSum > n) return;
        if(currSum == n) {
            if(rem == 0) {
                result.push_back(curr);
                return;
            }
            return;
        }
        
        if(rem < 0) return;
        
        for(int z = i-1;z>=1;z--) {
            if(currSum + z <= n) {
                curr.push_back(z);
                solve(z,rem-1,currSum+z,curr);
                curr.pop_back();
            }
        }
    }
    
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        if(n > 45) return result;
        
        this->n = n;
        this->k = k;
        
        solve(10,k,0,{});
        
        return result;
        
    }
};