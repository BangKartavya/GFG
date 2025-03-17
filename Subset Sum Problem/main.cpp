//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<int> arr;
    int n;
    int sum;
    vector<vector<int>> dp;
    
    bool solve(int i, int currSum) {
        if(i >= n) return false;
        if(currSum > sum) return false;
        if(currSum + arr[i] > sum) return false;
        if(currSum + arr[i] == sum) return true;
        
        if(dp[i][currSum] != -1) return dp[i][currSum];
        
        bool take = solve(i+1,currSum+arr[i]);
        bool noTake = solve(i+1,currSum);
        
        return dp[i][currSum] = take || noTake;
    }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        sort(begin(arr),end(arr));
        
        this->arr = arr;
        this->sum = sum;
        n = arr.size();
        dp.resize(n+1,vector<int>(sum+1,-1));
        return solve(0,0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends