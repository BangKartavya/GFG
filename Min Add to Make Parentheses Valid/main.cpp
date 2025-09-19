class Solution {
    public:
        int minParentheses(string& s) {
            // code here
            stack<char> stk;
            int extraClose = 0;

            for(char& ch : s) {
                if(ch == '(') stk.push(ch);
                else {
                    if(stk.empty()) {
                        extraClose++;
                    } else stk.pop();
                }
            }

            return extraClose + stk.size();
        }
};