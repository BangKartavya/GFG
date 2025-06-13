class Solution {
  private:
    vector<int> arr;
    int k;
    int n;
    
    bool isValid(int mid) {
        int timeTaken = 0;
        
        for(int i = 0;i<n;i++) {
            timeTaken += ceil((float)arr[i]/(float)mid);
        }
        
        return timeTaken <= k;
    }
  public:
    int kokoEat(vector<int>& arr, int k) {
        this->arr = arr;
        this->k = k;
        n = arr.size();
        
        int s = 1;
        int e = *max_element(begin(arr),end(arr));
        int ans = 0;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(isValid(mid)) {
                ans = mid;
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        
        return ans;
    }
};