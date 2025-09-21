class Solution {
  private:
    int largestArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> stk;
        
        int area = 0;
        
        for(int i = 0;i<=n;i++) {
            while(!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i-stk.top()-1;
                
                area = max(area,height*width);
            }
            stk.push(i);
        }
        
        return area;
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> heights(m);
        int ans = 0;
        
        for(int i = 0;i<n;i++) {
            for(int j =0;j<m;j++) {
                if(mat[i][j] == 1) heights[j]++;
                else heights[j] = 0;
            }
            
            ans = max(ans, largestArea(heights));
        }
        
        return ans;
    }
};