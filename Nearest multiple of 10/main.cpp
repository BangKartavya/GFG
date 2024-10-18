//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        string roundToNearest(string str) {
            if(str.back() < '6') {
                str.back() = '0';
            } else {
                str.back() = '9';
                int i;
                for(i = str.size() - 1; i >= 0; i--) {
                    if(str[i] == '9') {
                        str[i] = '0';
                    } else {
                        str[i] = (str[i] - '0' + 1) + '0';
                        break;
                    }
                }
                if(i == -1 and str[0] == '0') { str = '1' + str; }
            }
            return str;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends