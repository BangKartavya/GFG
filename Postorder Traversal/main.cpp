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
    vector<int> result;
    
    void dfs(Node* root) {
        if(!root) return;
        
        dfs(root->left);
        dfs(root->right);
        result.push_back(root->data);
    }
  public:
    vector<int> postOrder(Node* root) {
        dfs(root);
        
        return result;
    }
};