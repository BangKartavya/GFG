//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        string str1;
        string str2;
        string str3;
        string str4;
        int i = 0;
        
        while(str[i]!='/') str1+=str[i++];
        i++;
        while(str[i]!=',') str2+=str[i++];
        i+=2;
        while(str[i]!='/') str3+=str[i++];
        i++;
        while(str[i] != '\0') str4+=str[i++];
        
        double num1 = stod(str1)/stod(str2);
        double num2 = stod(str3)/stod(str4);
        
        if(num1>num2) return str1+'/'+str2;
        else if(num2 > num1) return str3+'/'+str4;
        
        return "equal";
         
        
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends