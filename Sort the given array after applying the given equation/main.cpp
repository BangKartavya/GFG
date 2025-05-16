//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n);
        
        int s = 0;
        int e = n-1;
        int i = n-1;
        int sign = 1;
        
        if(A < 0) sign = -1;
        
        while(s <= e) {
            int a = sign*(A*arr[s]*arr[s] + B*arr[s] + C);
            int b = sign*(A*arr[e]*arr[e] + B*arr[e] + C);
            
            if(a >= b) {
                result[i--] = a;
                s++;
            }
            else {
                result[i--] = b;
                e--;
            }
        }
        
        if(A < 0) {
            reverse(begin(result),end(result));
            for(int i =0;i<n;i++) result[i] *= -1;
        }
        return result;
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

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends