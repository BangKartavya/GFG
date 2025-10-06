class Solution {
  private:
    int n;
    
    vector<pair<int,int>> moves = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    bool isSafe(int i, int j, vector<vector<int>>& result) {
        return i >= 0 && i < n && j >=0 && j < n && result[i][j] == -1;
    }
    
    bool solve(int i, int j, vector<vector<int>>& result, int step) {
        
        result[i][j] = step;
        
        if(step == n*n-1) return true;
        
        for(auto& [dx,dy] : moves) {
            int x = i + dx;
            int y = j + dy;
            
            if(isSafe(x,y,result)) {
                if(solve(x,y,result,step+1)) return true;
            }
        }
        
        result[i][j] = -1;
        return false;
    }
  public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> result(n,vector<int>(n,-1));
        this->n = n;
        if(solve(0,0,result,0)) return result;
        
        return {{-1}};
        
    }
};