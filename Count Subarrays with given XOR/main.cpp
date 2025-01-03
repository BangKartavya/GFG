//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> xorMap; // Map to store frequency of prefix XORs
        int count = 0;                 // To count the number of subarrays
        int currentXor = 0;            // Initialize prefix XOR

        for (int num : arr) {
            currentXor ^= num; // Update the prefix XOR

            // Check if the prefix XOR equals k
            if (currentXor == k) {
                count++;
            }

            // Check if there exists a prefix XOR that gives the required XOR with k
            int requiredXor = currentXor ^ k;
            if (xorMap.find(requiredXor) != xorMap.end()) {
                count += xorMap[requiredXor];
            }

            // Update the frequency of the current prefix XOR in the map
            xorMap[currentXor]++;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends