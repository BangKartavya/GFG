class Solution {
  private:
    bool isPal(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
    
    vector<vector<string>> result;
    string s;
    int n;
    
    void solve(int i, vector<string>& curr) {
        if(i >= n) {
            result.push_back(curr);
            return;
        }
        
        string temp;
        
        for(int k = i;k<n;k++) {
            temp.push_back(s[k]);
            if(isPal(temp)) {
                curr.push_back(temp);
                solve(k+1,curr);
                curr.pop_back();
            }
        }
        
    }
  public:
    vector<vector<string>> palinParts(string &s) {
        
        this->s = s;
        n = s.size();
        vector<string> curr;
        solve(0,curr);
        
        return result;
    }
};