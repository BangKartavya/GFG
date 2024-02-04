//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* reverseLL(Node* root){
        Node* p=0;
        Node* c=root;
        Node* n=0;
        
        while(c){
            n=c->next;
            c->next=p;
            p=c;
            c=n;  
        }
        
        return p;
    }
    
    string LL2S(Node* head) {
        string s;
        
        bool skipTrailZero = false;
        while (head) {
            if (head->data) skipTrailZero = true;
            if (skipTrailZero) {
                s += (head->data + '0');
            }
            head = head->next;
        }
        
        return s;
    }

    
    Node* subLinkedList(Node* head1, Node* head2) {
        string s1 = LL2S(head1), s2 = LL2S(head2);
        Node* root = new Node(0);
        Node* temp = root;
        
        if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) {
            swap(s1, s2);
        }
        
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        
        for (; i >= 0; i--, j--) {
            int n1 = s1[i] - '0';
            int n2 = (j >= 0) ? (s2[j] - '0') : 0;
            
            if (n1 < n2) { 
                temp->next = new Node(n1 + 10 - n2);
                if (i > 0) {
                    s1[i - 1]--;  // Borrow from the previous digit
                }
            } else {
                temp->next = new Node(n1 - n2);
            }
    
            temp = temp->next; 
        }
        
        root = reverseLL(root->next);
        while(root && root->data==0) {
            root=root->next; 
        }
        // empty if both are zero
        if(root==nullptr) root=new Node(0);
        return root;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends