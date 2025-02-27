//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    stack<int> stk;
    int mini;
  public:
    Solution() {
        mini = INT_MAX;
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(stk.empty()) {
            stk.push(x);
            mini = x;
        }
        else {
            if(x < mini) {
                stk.push(2 * x - mini);
                mini = x;
            }
            else stk.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if(stk.empty()) return;
        
        int top = stk.top();
        stk.pop();
        
        if(top < mini) {
            mini = 2 * mini - top;
        }
        
    }

    // Returns top element of the Stack
    int peek() {
        if(stk.empty()) return -1;
        
        int top = stk.top();
        
        return (top < mini) ? mini : top;
    }

    // Finds minimum element of Stack
    int getMin() {
        if(stk.empty()) return -1;
        
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends