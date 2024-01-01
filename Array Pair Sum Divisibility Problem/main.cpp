//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size()%2!=0) return false;
        
         unordered_map<int,int>mp;
     
        for (int i = 0; i < nums.size(); i++) {
            int mod = nums[i] % k;
            mp[mod]++;
        }
    
        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i] % k;
            int target = (num1 == 0) ? 0 : k - num1;
    
            if (mp[num1] == 0) {
                continue;
            }
    
    
            if (num1 == target) {
                if (mp[num1] < 2) {
                    return false;
                }
            } else if (mp[target] == 0) {
                return false;
            }
    
           
            mp[num1]--;
            mp[target]--;
        }
    
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends