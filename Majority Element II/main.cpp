    //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        // Function to find the majority elements in the array
        vector<int> findMajority(vector<int>& arr) {
            int n = arr.size();

            int major_1 = -1;
            int cnt_1 = 0;

            int major_2 = -1;
            int cnt_2 = 0;

            for(int i = 0; i < n; i++) {
                if(major_1 == -1) {
                    major_1 = arr[i];
                    cnt_1 = 1;
                } else if(major_2 == -1) {
                    major_2 = arr[i];
                    cnt_2 = 1;
                }

                if(arr[i] == major_1) cnt_1++;
                else if(arr[i] == major_2) cnt_2++;
                else {
                    major_1 = major_2;
                    cnt_1 = cnt_2;
                    major_2 = arr[i];
                    cnt_2 = 1;
                }
            }

            cnt_1 = 0;
            cnt_2 = 0;

            for(auto i : arr) {
                if(i == major_1) cnt_1++;
                if(i == major_2) cnt_2++;
            }

            if(cnt_1 > n / 3 && cnt_2 > n / 3) {
                if(major_1 > major_2) return {major_2, major_1};

                return {major_1, major_2};
            }
            if(cnt_1 > n / 3) return {major_1};
            if(cnt_2 > n / 3) return {major_2};

            return {};
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
        if(ans.empty()) {
            cout << "[]";
        } else {
            for(auto& i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends