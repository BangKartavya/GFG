//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
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
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    bool isVowel(char c){
        return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
    }
    
    struct Node* arrangeCV(Node *head)
    {
       if(!head or !head->next)return head;
       struct Node* vow = new Node('&');
       struct Node* cons = new Node('$');
       struct Node* v = vow;
       struct Node* c = cons; 
       struct Node* prev = NULL;
       struct Node* curr = head;
       while(curr){
           if(isVowel(curr->data)){
               prev = curr;
               curr=curr->next;
               v->next = prev;
               prev->next = NULL;
               v=v->next;
           }
           else{
               prev = curr;
               curr=curr->next;
               c->next=prev;
               prev->next = NULL;
               c=c->next;
           }
       }
       if(!vow->next)return cons->next;
       if(!cons->next) return vow->next;
       struct Node* newhead = vow->next;
       v->next = cons->next;
       return newhead;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends