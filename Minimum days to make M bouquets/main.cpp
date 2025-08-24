class Solution {
  private:
    vector<int> arr;
    int n;
    int m;
    int k;
    
    bool isValid(int maxDays) {
        int count = 0;
        int bCount = 0;
        
        for(int i = 0;i<n;i++) {
            if(arr[i] <= maxDays) {
                count++;
            }    
            else count = 0;
            
            if(count == k) {
                bCount++;
                count = 0;
            }
        }
        
        return bCount >= m;
    }
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if(k * m > arr.size()) return -1;
        
        this->arr = arr;
        n = arr.size();
        this->m = m;
        this->k = k;
        
        int s = *min_element(begin(arr),end(arr));
        int e = 1e9;
        int ans = -1;
        
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