class Solution {
  private:
    string bin(int n) {
        string res;
        
        while(n > 1) {
            res += ((n%2) + '0');
            n/=2;
        }
        
        if(n) res += '1';
        
        reverse(begin(res),end(res));
        
        return res;
    }
  public:
    vector<string> generateBinary(int n) {
        vector<string> result;
        
        
        for(int i = 1;i<=n;i++) {
            result.push_back(bin(i));
        }
        
        return result;
    }
};