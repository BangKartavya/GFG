class Solution {
  private:
    int diff(string& t1,string& t2) {
        int hr1 = stoi(t1.substr(0, 2));
        int mn1 = stoi(t1.substr(3, 2));
        int sc1 = stoi(t1.substr(6, 2));
        int hr2 = stoi(t2.substr(0, 2));
        int mn2 = stoi(t2.substr(3, 2));
        int sc2 = stoi(t2.substr(6, 2));
        int time1 = hr1 * 3600 + mn1 * 60 + sc1;
        int time2 = hr2 * 3600 + mn2 * 60 + sc2;
        return abs(time2 - time1 + 86400) % 86400;
    }
  public:
    int minDifference(vector<string> &arr) {
        sort(begin(arr),end(arr));
        int d = INT_MAX;
        int n = arr.size();
        
        for(int i =0 ;i<n;i++) {
            string t1 = arr[i];
            string t2 = arr[(i+1)%n];
            
            d = min(d,diff(t1,t2));
        }
        
        return d;
    }
};
