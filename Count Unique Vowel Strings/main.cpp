class Solution {
  private:
    int fact(int n) {
        if(n == 0) return 1;
        
        return n * fact(n-1);
    }
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<char,int> mp;
        string vow = "aeiou";
        
        for(char& ch: s) {
            if(vow.find(ch) != string::npos) mp[ch]++;
        }
        
        if(mp.size() == 0) return 0;
        
        int mul = 1;
        
        for(auto& it: mp) mul *= it.second;
        
        return mul * fact(mp.size());
    }
};