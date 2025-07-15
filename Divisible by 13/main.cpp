class Solution {
  public:
    bool divby13(string &s) {
        int num = 0;
        
        for(char& ch: s) {
            num = num * 10 + (ch-'0');
            
            if(num >= 13) num %= 13;
        }
        
        return num == 0;
    }
};