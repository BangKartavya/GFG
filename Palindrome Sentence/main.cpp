class Solution {
  public:
    bool isPalinSent(string &s) {
        string cleaned;
        
        for(char& ch: s) {
            if(isalnum(ch)) cleaned.push_back(tolower(ch));
        }
        
        int i = 0;
        int j = cleaned.size()-1;
        
        while(i < j) {
            if(cleaned[i++] != cleaned[j--]) return false;
        }
        
        return true;
    }
};