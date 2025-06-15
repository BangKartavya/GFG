class Solution {
  private:
    vector<int> arr;
    int k;
    
    bool isValid(int mid) {
        int res = 0;
        
        for(int& i: arr) {
            res += ceil(float(i)/float(mid));
        }
        
        return res <= k;
    }
    
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        this->arr = arr;
        this->k = k;
        
        int s = 1;
        int e = *max_element(begin(arr),end(arr));
        int ans = 0;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(isValid(mid)) {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return ans;
        
    }
};
