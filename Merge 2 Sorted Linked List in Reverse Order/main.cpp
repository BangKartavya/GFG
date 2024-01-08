//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    void insert(Node** root,int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = *root;
        *root=temp;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        vector<int> ans;
        Node* temp1 = node1;
        Node* temp2 = node2;
        
        while(temp1!=nullptr) {
            ans.push_back(temp1->data);
            temp1 = temp1->next;
        }
        
        while(temp2!=nullptr) {
            ans.push_back(temp2->data);
            temp2 = temp2->next;
        }
        
        sort(ans.begin(),ans.end());
        
        Node* temp = NULL;
        for(int i = 0;i<ans.size();i++) insert(&temp,ans[i]);
        return temp;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends