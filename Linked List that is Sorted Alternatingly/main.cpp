//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    Node* rev(Node* head) {
        if(head==nullptr || head->next==nullptr) return head;
        
        Node* temp = rev(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return temp;
    }
    // your task is to complete this function
    void sort(Node **h)
    {   
        Node* head = *h;
         
         if(head->next==nullptr) return;
         
         Node* ptr1 = head;
         Node* ptr2 = head->next;
         Node* dummy = head->next;
         
         while(ptr2!=nullptr && ptr2->next!=nullptr) {
             ptr1->next = ptr2->next;
             ptr1 = ptr1->next;
             
             ptr2->next = ptr1->next;
             ptr2 = ptr2->next;
         }
         
         ptr1->next = rev(dummy);
         
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends