class Solution {
  private:
    vector<int> arr;
    
    int firstIdx(int s, int e, int x) {
        int ans = -1;
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(arr[mid] == x) {
                ans = mid;
                e = mid-1;
            }
            else if(arr[mid] > x) {
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return ans;
    }
    int lastIdx(int s, int e, int x) {
        int ans = -1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(arr[mid] == x) {
                ans = mid;
                s = mid+1;
            }
            else if(arr[mid] > x) {
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return ans;
    }
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        this->arr = arr;
        vector<int> res;
        
        for(vector<int>& query : queries) {
            int l = query[0];
            int r = query[1];
            int x = query[2];
            
            int s = firstIdx(l,r,x);
            int e = lastIdx(l,r,x);
            
            
            if(s != -1 && e != -1) res.push_back(e-s+1);
            else res.push_back(0);
        }
        
        return res;
    }
};