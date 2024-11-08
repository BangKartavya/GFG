//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    std::string addStrings(const std::string &num1, const std::string &num2) {
    std::string result;
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    // Perform addition from the last digit of both strings
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? num1[i--] - '0' : 0;
        int digit2 = j >= 0 ? num2[j--] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    // Reverse the result to get the final answer
    std::reverse(result.begin(), result.end());

    // Remove any leading zeros
    auto first_non_zero = result.find_first_not_of('0');
    if (first_non_zero != std::string::npos) {
        result = result.substr(first_non_zero);
    } else {
        result = "0";  // if all are zeros, return "0"
    }

    return result;
}
    string minSum(vector<int> &arr) {
        // code here
        string ans="";
        long long sum=0;
        sort(arr.begin(),arr.end());
        //047+35=82
        
        //[2,3,4,5,6,8]
        int N=arr.size();
        string ans1="",ans2="";
        for(int i=0;i<N;i++){
            if(i%2==0) ans1+=to_string(arr[i]);
            else ans2+=to_string(arr[i]);
        }
        return addStrings(ans1,ans2);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends