class Solution {
  private:
    vector<int> arr;
    int k;
    int w;
    int n;
    
    bool isValid(int mid){
    vector<int>diff(n+1,0);  // difference array to track water added
    int totalWaterUsed=0;
    int water=0; // current water effect at position i

    for(int i=0;i<n;i++){
        water+=diff[i];  // update current water at i
        int currentHeight=arr[i]+water;

        if(currentHeight<mid){
            int need=mid-currentHeight;
            totalWaterUsed+=need;
            if(totalWaterUsed>k)return false;
            
            water+=need;               // apply water from i
            diff[i]+=need;
            if (i+w<n)diff[i+w]-=need; // stop water effect after w positions
        }
    }
    return true;
  }
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        this->arr = arr;
        this->k = k;
        this->w = w;
        n = arr.size();
        
        int s = *min_element(begin(arr),end(arr));
        int e = *max_element(begin(arr),end(arr)) + k;
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