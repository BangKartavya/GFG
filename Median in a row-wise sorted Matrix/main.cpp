class Solution {
  private:
    vector<vector<int>> mat;
    
    int smallThan(int val) {
        int cnt = 0;
        
        for(vector<int>& row: mat) {
            cnt += upper_bound(begin(row),end(row),val)-begin(row);
        }
        /*
        cout << "val : " << val << endl;
        cout << "cnt : " << cnt << endl;
        */
        return cnt;
    }
  public:
    int median(vector<vector<int>> &mat) {
        this->mat = mat;
        int n = mat.size();
        int m = mat[0].size();
        
        int s = INT_MAX;
        int e = 0;
        
        for(int i = 0;i<n;i++) {
            s = min(s,mat[i][0]);
            e = max(e,mat[i][m-1]);
        }
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            int v = smallThan(mid);
            
            if(v <= n*m/2) s = mid+1;
            else e = mid-1;
        }
        
        return s;
    }
};
