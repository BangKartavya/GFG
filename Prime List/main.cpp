//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
};

void printList(Node* node) {
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
    private:
        bool isPrime(int val) {
            if(val == 0 || val == 1) return false;

            for(int i = 2; i <= sqrt(val); i++) {
                if(val % i == 0) return false;
            }

            return true;
        }
        int nearestPrime(int n) {
            int prime1 = 0;
            int prime2 = 0;

            if(n == 1) return 2;

            for(int i = n; i > 1; i--) {
                if(isPrime(i)) {
                    prime1 = i;
                    break;
                }
            }

            for(int i = n; i < n * n; i++) {
                if(isPrime(i)) {
                    prime2 = i;
                    break;
                }
            }

            if(n - prime1 <= prime2 - n) return prime1;

            return prime2;
        }

    public:
        Node* primeList(Node* head) {
            Node* temp = head;

            while(temp) {
                if(isPrime(temp->val)) {
                    temp = temp->next;
                    continue;
                }

                temp->val = nearestPrime(temp->val);
                temp = temp->next;
            }

            return head;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }

        if(arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for(int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends