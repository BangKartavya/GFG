class Solution {
  public:
    string caseSort(string& s) {
        map<char,int> mpLower;
        map<char,int> mpUpper;
        
        for(char& ch: s) {
            if(ch-'a' < 0) {
                mpUpper[ch]++;
            }
            else mpLower[ch]++;
        }
        
        string sortedString;
        
        auto itLower = mpLower.begin();
        auto itUpper = mpUpper.begin();
        int i = 0;
        while(itLower != mpLower.end() && itUpper != mpUpper.end()) {
            if(s[i++]-'a' < 0) {
                sortedString.push_back(itUpper->first);
                itUpper->second--;
                if(itUpper->second == 0) {
                    itUpper++;
                }
            }
            else {
                sortedString.push_back(itLower->first);
                itLower->second--;
                if(itLower->second == 0) {
                    itLower++;
                }
            }
        }
        
        while(itLower != mpLower.end()) {
            sortedString.push_back(itLower->first);
            itLower->second--;
            if(itLower->second == 0) {
                itLower++;
            }
        }
        
        while(itUpper != mpUpper.end()) {
            sortedString.push_back(itUpper->first);
            itUpper->second--;
            if(itUpper->second == 0) {
                itUpper++;
            }
        }
        
        return sortedString;
        
        
    }
};