//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        vector<int> sorted;
        
        int i =0;
        int j =0;
        
        while(i<arr1.size() && j < arr2.size()) {
            if(arr1[i] > arr2[j]) {
                sorted.push_back(arr2[j]);
                j++;
            }
            else {
                sorted.push_back(arr1[i]);
                i++;
            }
        }
        while(i<arr1.size()) sorted.push_back(arr1[i++]);
        while(j<arr2.size()) sorted.push_back(arr2[j++]);
        
        int s = 0;
        int e = sorted.size() - 1;
        
        while(s<=e) {
            int mid = s + (e-s)/2;
            
            if(mid == k-1) return sorted[mid];
            else if(mid < k-1) s = mid+1;
            else e = mid-1;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends