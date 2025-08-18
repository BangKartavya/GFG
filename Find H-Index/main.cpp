class Solution {
  private:
    vector<int> citations;
    int n;
    
    bool isValid(int h) {
        int count = 0;
        
        for(int i = 0;i<n;i++) {
            if(citations[i] >= h) count++;
        }
        
        return count >= h;
    }
  public:
    int hIndex(vector<int>& citations) {
        this->citations = citations;
        n = citations.size();
        
        int s = 0;
        int e = 1e9;
        int ans = -1;
        
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