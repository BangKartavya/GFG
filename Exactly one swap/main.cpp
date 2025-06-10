class Solution {
  public:
    int countStrings(string &s) {
        int n = s.size();
        int freq[26] = {0};
        int count = 0;
        bool flag = false;

        for(int i =0;i<n;i++){
            count += n-i-1;
            count -= freq[s[i]-'a'];
            if(freq[s[i]-'a'] != 0)flag = true;
            freq[s[i]-'a']++;
        }

        return count+flag;
        
    }
};
