//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    
    Node* reverseLL(struct Node* head) {
        if(head==NULL || head->next == NULL) return head;
        
        Node* curr = head;
        Node* dummy = NULL;
        while(curr!=NULL) {
            Node* temp = curr->next;
            curr->next = dummy;
            dummy=curr;
            curr = temp;
        }
        return dummy;
    }
    
    void rearrange(struct Node *head)
    {
        if(head==NULL || head->next == NULL) {
            return;
        }
        Node* even = head;
        Node* odd = head->next;
        Node*per = odd;
        while(even->next && odd->next) {
            even->next = even->next->next;
            even = even->next;
            odd->next = odd->next->next;
            odd = odd->next;
        }
        Node* rev = reverseLL(per);
        even->next = rev;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends