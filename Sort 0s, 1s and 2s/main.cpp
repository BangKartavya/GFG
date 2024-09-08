//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        for(auto i: arr) {
            if(i == 0) zeros++;
            if(i == 1) ones++;
            if(i == 2) twos++;
        }
        int i =0;
        for(int j =0;j<zeros && i < arr.size();j++) {
            arr[i++] = 0;
        }
        for(int j =0;j<ones && i < arr.size();j++) {
            arr[i++] = 1;
        }
        for(int j =0;j<twos && i < arr.size();j++) {
            arr[i++] = 2;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends