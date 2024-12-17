//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    vector<int> stalls;
    int n;
    int k;
    
    bool isPossible(int min_dist) {
        int cnt = 1;
        int last = stalls[0];
        
        for(int i = 1;i<n;i++) {
            if(stalls[i]-last >= min_dist) {
                cnt++;
                last = stalls[i];
            }
            if(cnt >= k) return true;
        }
        
        return cnt>=k;
        
    }
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(begin(stalls),end(stalls));
        
        this->stalls = stalls;
        this->k = k;
        n = stalls.size();
        
        int s = 0;
        int e = 1e9;
        int ans = -1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(isPossible(mid)) {
                ans = mid;
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends