//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Meet {
    int start;
    int end;
};

bool cmp(Meet m1, Meet m2) {
    return m2.end > m1.end;
}

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<Meet> v;
        for(int i =0;i<n;i++) v.push_back({start[i],end[i]});
        
        sort(v.begin(),v.end(),cmp);
        int cnt = 0;
        int lastTime = -1;
        
        for(auto i: v) {
            if(i.start > lastTime) {
                cnt++;
                lastTime = i.end;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends