//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}

class Solution {
  private:
    vector<pair<int,int>> vp;
    int n;
    
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        n = start.size();
        
        for(int i = 0;i<n;i++) {
            vp.push_back({start[i],finish[i]});
        }
        
        sort(begin(vp),end(vp),cmp);
        
        int dep = vp[0].second;
        int cnt = 1;

        for(int i = 1;i<n;i++) {
            if(vp[i].first > dep) {
                cnt++;
                dep = max(vp[i].second,dep);
            }
        }        
        
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends