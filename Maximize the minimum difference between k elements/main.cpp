class Solution {
  private:
    vector<int> arr;
    int n;
    int k;
    
    bool isValid(int minDiff) {
        if(arr[n-1]-arr[0] < minDiff) return false;
        
        int elems = 1;
        int lastElem = arr[0];
        
        for(int i = 1;i<n;i++) {
            if(arr[i] - lastElem >= minDiff) {
                elems++;
                lastElem = arr[i];
            }
        }
        
        return elems >= k;
    }
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        sort(begin(arr),end(arr));
        this->arr = arr;
        n = arr.size();
        this->k = k;
        
        int s = 0;
        int e = 1e9;
        int ans = 0;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(isValid(mid)) {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        
        return ans;
    }
};
