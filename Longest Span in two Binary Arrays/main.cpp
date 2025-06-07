class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        
        vector<int> temp(n);
        
        for(int i = 0;i<n;i++) temp[i] = a1[i] - a2[i];
        
        int rem = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0;i<n;i++) {
            rem += temp[i];
            
            if(rem == 0) {
                ans = max(ans,i+1);
            }
            
            if(mp.find(rem) != mp.end()) {
                ans = max(ans,i-mp[rem]);
            }
            
            else mp[rem] = i;
        }
        
        return ans;
    }
};