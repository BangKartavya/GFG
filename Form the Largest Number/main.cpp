bool cmp(const string& a, const string& b) {
    return (a+b) < (b+a);
}

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        vector<string> r;
        
        for(int& i: arr) r.push_back(to_string(i));
        
        sort(rbegin(r),rend(r),cmp);
        
        string res;
        
        for(string& i: r) res += i;
        
        int i = 0;
        int n = res.size();
        
        while(i < n - 1 && res[i] == '0') i++;
        
        return res.substr(i);
    }
};