//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        vector<Node*> v;
        if(!head) return v;
        
        if(!head->next) return {head};
        
        Node* cur1 = new Node(head->data);
        
        Node* cur2 = new Node(head->next->data);
        
        Node* temp1 = cur1;
        Node* temp2 = cur2;
        
        Node* temp = head;
        int i = 0;
        
        while(temp) {
            if(i%2 == 0) {
                temp1->next = temp;
                temp1 = temp1->next;
            }
            else {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            
            temp = temp->next;
            i++;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        
        v.push_back(cur1->next);
        v.push_back(cur2->next);
        
        return v;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends