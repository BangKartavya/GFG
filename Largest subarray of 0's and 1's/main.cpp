//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int answer = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        int n = arr.size();
        
        for(int i = 0;i<n;i++) {
            if(arr[i] == 0) sum--;
            if(arr[i] == 1) sum++;
            
            if(sum == 0 || mp.find(sum) != mp.end()) {
                answer = max(answer,i-mp[sum]+1);
            }
            else if(mp.find(sum) == mp.end()) mp[sum] = i+1;
        }
        
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends