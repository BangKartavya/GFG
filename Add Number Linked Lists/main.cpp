//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* nxt = NULL;
        Node* prev = NULL;
        
        
        while(curr){
            nxt =curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
  public:
    Node* addTwoLists(Node* num1, Node* num2) {


        int res = 0, i = 0;


        num1 = reverse(num1);
        num2 = reverse(num2);


        Node* head1 = num1;
        Node* head2 = num2;


        Node* dummy = new Node(-1);
        Node* dummyHead = dummy;


        int carry = 0;


        while(head1 && head2){


            int sum = head1->data + head2->data + carry;
            carry = sum/10;

            dummyHead -> next = new Node(sum%10);
            dummyHead = dummyHead->next;
            
            head1 = head1->next;
            head2 = head2->next;


        }
        while(head1){


            int sum = head1->data + carry;
            carry = sum/10;

            dummyHead -> next = new Node(sum%10);
            dummyHead = dummyHead->next;
            
            head1 = head1->next;
            
        }
        
         while(head2){


            int sum = head2->data + carry;
            carry = sum/10;

            dummyHead -> next = new Node(sum%10);
            dummyHead = dummyHead->next;
           
            head2 = head2->next;
            
        }
        if(carry){
            

            dummyHead -> next = new Node(carry%10);
            dummyHead = dummyHead->next;
            
        }
        
        Node* newHead = dummy->next ;
        delete dummy;
        newHead = reverse(newHead);
        
        // to avoid zero in starting


        while(newHead->data ==0){
            newHead = newHead->next;
        }
        return newHead;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends