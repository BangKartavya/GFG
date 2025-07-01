class Solution {
  public:
    int substrCount(string &s, int k) {
        unordered_map<char,int> mp;
        
        int n = s.size();
        int i = 0;
        int j = k-1;
        int count = 0;
        
        for(int i = 0;i<=j;i++) {
            mp[s[i]]++;
        }
        
        while(j < n) {
            if(mp.size() == k-1) {
                // cout << "j : " << j << endl;
                count++;
            }
            
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
            j++;
            mp[s[j]]++;
        }
        
        return count;
        
    }
};