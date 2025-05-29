/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  private:
    int maxLen = 0;
    int sum = 0;
    
    void dfs(Node* root, int s ,int len) {
        if(!root) {
            if(len >= maxLen) {
                if(len == maxLen) {
                    sum = max(sum,s);
                }
                else sum = s;
                maxLen = len;
            }
            
            return;
        }
        
        dfs(root->left,s+root->data,len+1);
        dfs(root->right,s+root->data,len+1);
    }
    
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        dfs(root,0,0);
        
        return sum;
        
    }
};