/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    int l;
    int r;
    
    Node* dfs(Node* root) {
        if(!root) return nullptr;
        
        if(root->data >= l && root->data <= r) {
            Node* a = dfs(root->left);
            Node* b = dfs(root->right);
            
            root->left = a;
            root->right = b;
        
            return root;
        }
        
        else if(root->data < l) {
            root->left = nullptr;
            Node* a = dfs(root->right);
            return a;
        }
        
        root->right = nullptr;
        Node* b = dfs(root->left);
        return b;
        
    }
    
  public:
    Node* removekeys(Node* root, int l, int r) {
        this->l = l;
        this->r = r;
        
        return dfs(root);
        
    }
};