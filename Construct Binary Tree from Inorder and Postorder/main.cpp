//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    Node* construct(int Inorder[],int Postorder[],int postin,int postout,int in,int inout, unordered_map<int,int>&mp){
        if(postin>postout and in>inout)return NULL;
        Node* root=new Node(Postorder[postout]);
        int numsLeft=mp[root->data]-in;
        root->left=construct(Inorder,Postorder,postin,postin+numsLeft-1,in,mp[root->data]-1,mp);
        root->right=construct(Inorder,Postorder,postin+numsLeft,postout-1,mp[root->data]+1,inout,mp);
        return root;
    }

    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        return construct(in,post,0,n-1,0,n-1,mp);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends