class Solution {
    public:
        int evaluatePostfix(vector<string>& arr) {
            // code here
            stack<int> stk;

            for(string& s : arr) {
                if(!(s == "+" || s == "-" || s == "*" || s == "/" || s == "^")) {
                    // cout << "s : " << s << endl;
                    stk.push(stoi(s));
                } else {
                    int b = stk.top();
                    stk.pop();
                    int a = stk.top();
                    stk.pop();

                    if(s == "+") stk.push(a + b);
                    else if(s == "*") stk.push(a * b);
                    else if(s == "-") stk.push(a - b);
                    else if(s == "^") stk.push(pow(a, b));
                    else stk.push(floor((float)a / (float)b));
                }
            }

            return stk.top();
        }
};