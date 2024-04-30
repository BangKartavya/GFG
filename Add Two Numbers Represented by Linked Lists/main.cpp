//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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

class Solution
{
    public:
    Node* Zero(Node* head) {
        if(head->data==0) {
            while(head->data==0) {
                head = head->next;
                if(!head) return new Node(0);
            }
        }
        return head;
    }
    //Function to add two numbers represented by linked list.
    Node* rev(Node* head) {
        Node* prev = NULL;
        while(head) {
            Node* next = head->next;
            head->next=prev;
            prev= head;
            head = next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        Node* temp1 = rev(num1);
        Node* temp2 = rev(num2);
        
        Node* d = new Node(0);
        Node* t = d;
        int ans = 0;
        
        while(temp1 || temp2 || ans) {
            int sum = 0;
            if(temp1) {
                sum+=temp1->data;
                temp1 = temp1->next;
            }
            if(temp2) {
                sum+=temp2->data;
                temp2 = temp2->next;
            }
            sum+=ans;
            Node* newNode = new Node(sum%10);
            ans = sum/10;
            t->next = newNode;
            t = t->next;
        }
        d->next = rev(d->next);
        d->next = Zero(d->next);
        
        return d->next;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends