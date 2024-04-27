//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    void mergesort(vector<int>&ans,int s,int e){
        int mid=s+(e-s)/2;
    int leftlen=mid-s+1;
    int rightlen=e-mid;
    int *left=new int[leftlen];
    int *right=new int[rightlen];
    int k=s;
    for(int i=0;i<leftlen;i++){
        left[i]=ans[k++];
    }
    k=mid+1;
    for(int i=0;i<rightlen;i++){
        right[i]=ans[k++];
    }
    int l=0,r=0;
    int f=s;
    while(l<leftlen && r<rightlen){
        if(left[l]<right[r]){
            ans[f]=left[l];
            f++;
            l++;
        }
        else{
            ans[f]=right[r];
            f++;
            r++;
        }
    }
    while(l<leftlen){
            ans[f++]=left[l++];
    }
     while(r<rightlen){
            ans[f++]=right[r++];
    }
    delete[] left;
    delete[] right;
    }
    void merge(vector<int>&ans,int s,int e){
        if(s>=e){
            return;
        }
        int mid=s+(e-s)/2;
        merge(ans,s,mid);
        merge(ans,mid+1,e);
        mergesort(ans,s,e);
    }
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        vector<int>ans;
        Node* curr=head;
        while(curr!=NULL){
            ans.push_back(curr->data);
            curr=curr->next;
        }
        // sort(ans.begin(),ans.end());
        int s=0,e=ans.size()-1;
        merge(ans,s,e);
        curr=head;
        int i = 0;
        while(curr != NULL && i < ans.size()){
        curr->data=ans[i];
        curr=curr->next;
        i++;
    }
        return head;
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends