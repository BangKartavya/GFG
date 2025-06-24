class Solution {
  public:
    string maxSubseq(string& s, int k) {
        stack<char> stk;

        for(char& ch: s) {
            if(stk.empty()) {
                stk.push(ch);
            }
            else {
                while(!stk.empty() && stk.top() < ch && k > 0) {
                    stk.pop();
                    k--;
                }
                
                stk.push(ch);
            }
        }
        
        while(k > 0) {
            stk.pop();
            k--;
        }
        
        string result;
        
        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        
        reverse(begin(result),end(result));
        
        return result;
        
    }
};
