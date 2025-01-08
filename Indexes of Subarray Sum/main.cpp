//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        vector<int> subarraySum(vector<int>& arr, int target) {
            int s = accumulate(begin(arr), end(arr), 0);

            if(s < target) return {-1};

            int n = arr.size();

            s = 0;
            int e = 0;

            vector<int> ans;
            int sum = 0;

            while(e < n) {
                sum += arr[e];

                if(sum == target) return {s + 1, e + 1};

                while(sum > target) {
                    sum -= arr[s++];

                    if(sum == target) return {s + 1, e + 1};
                }

                e++;

                // cout << "sum : " << sum << endl;
                // cout << "s : " << s << endl;
                // cout << "e : " << e << endl;
            }

            return {-1};
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for(int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends