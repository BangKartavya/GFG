//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)    {
        vector<int> v,v1;
        while(head){
              v.push_back(head->data);   
              head=head->next;
        }
        for(int i=0;i<v.size()-1;i++){
            int s=0;
            for(int j=i+1;j<v.size();j++){
                if(v[j]>v[i]) {s=1;break;}
            }
            if(s==0) v1.push_back(v[i]);
        }
        v1.push_back(v[v.size()-1]);
        Node* l1=new Node(v1[0]);
        Node* ans=l1;
        for(int i=1;i<v1.size();i++){
            Node* next=new Node(v1[i]);
            l1->next=next;
            l1=l1->next;
        }
        return ans;
    }
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends