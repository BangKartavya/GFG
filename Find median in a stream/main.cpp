//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        vector<double> getMedian(vector<int>& arr) {
            vector<double> ans;
            priority_queue<int> maxHeap;
            priority_queue<int, vector<int>, greater<int>> minHeap;

            ans.push_back(arr[0]);
            minHeap.push(arr[0]);

            for(int i = 1; i < arr.size(); i++) {
                int curr = arr[i];

                if(i % 2 != 0) {
                    int minInMinHeap = minHeap.top();
                    minHeap.pop();
                    minHeap.push(max(curr, minInMinHeap));
                    maxHeap.push(min(curr, minInMinHeap));
                    ans.push_back(((double)minHeap.top() + maxHeap.top()) / 2.0);
                } else {
                    int minInMinHeap = minHeap.top();
                    int maxInMaxHeap = maxHeap.top();
                    if(curr > minInMinHeap) {
                        minHeap.push(curr);
                        ans.push_back(minInMinHeap);
                    } else if(curr < maxInMaxHeap) {
                        maxHeap.pop();
                        minHeap.push(maxInMaxHeap);
                        maxHeap.push(curr);
                        ans.push_back(maxInMaxHeap);
                    } else {
                        minHeap.push(curr);
                        ans.push_back(curr);
                    }
                }
            }
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
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for(auto& i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends