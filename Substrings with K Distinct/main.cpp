class Solution {
  private:
    int solve(string& s, int k) {
        int freq[26] = {0};
        
        int n = s.size();
        int l = 0;
        int r = 0;
        
        int dist = 0;
        int count = 0;
        
        while(r < n) {
            freq[s[r]-'a']++;
            if(freq[s[r]-'a'] == 1) dist++; 
            
            while(dist > k) {
                freq[s[l]-'a']--;
                if(freq[s[l]-'a'] == 0) dist--;
                l++;
            }
            r++;
            count += (r-l+1);
        }
        
        return count;
    }
  public:
    int countSubstr(string& s, int k) {
        return solve(s,k)-solve(s,k-1);
    }
};