/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  private:
    int sum = 0;
    
    void dfs(Node* root) {
        if(!root) return;
        
        dfs(root->right);
        int val = root->data;
        root->data = sum;
        sum += val;
        dfs(root->left);
    }
  public:
    void transformTree(Node *root) {
        sum = 0;
        dfs(root);
    }
};