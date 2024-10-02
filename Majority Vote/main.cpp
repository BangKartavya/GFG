//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        // Function to find the majority elements in the array
        vector<int> findMajority(vector<int>& nums) {
            // Your code goes here.
            vector<int> ans;
            int c1 = 0, c2 = 0;
            int e1 = -1, e2 = -1;
            int n = nums.size();

            for(auto z : nums) {
                if(c1 == 0 && z != e2) {
                    e1 = z;
                    c1++;
                } else if(c2 == 0 && z != e1) {
                    e2 = z;
                    c2++;
                } else {
                    if(z == e1)
                        c1++;
                    else if(z == e2)
                        c2++;
                    else {
                        c1--;
                        c2--;
                    }
                }
            }

            c1 = 0;
            c2 = 0;
            for(auto z : nums) {
                if(z == e1) c1++;
                if(z == e2) c2++;
            }

            if(c1 > n / 3)
                ans.push_back(e1);
            if(c2 > n / 3)
                ans.push_back(e2);
            if(ans.size() == 0)
                return {-1};
            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while(ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for(auto& i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends