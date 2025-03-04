//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<int> arr;
    int n;
    vector<vector<int>> dp;
    
    int solve(int i, int lastValIdx) {
        if(i >= n) return 0;
        
        if(dp[i][lastValIdx+1] != -1) return dp[i][lastValIdx+1];
        
        int take = 0;
        
        if(lastValIdx == -1 || arr[i] > arr[lastValIdx]) {
            take = 1 + solve(i+1,i);
        }
        
        int noTake = solve(i+1,lastValIdx);
        
        return dp[i][lastValIdx+1] = max(take, noTake);
    }
  public:
    int lis(vector<int>& arr) {
        this->arr = arr;
        n = arr.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends