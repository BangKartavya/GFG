
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution {
  private:
    unordered_set<int> s;
    bool isDeadEndLeaf(Node* root, int upperBound, int lowerBound) {
        s.insert(root->data);
        
        bool flagLeft = false;
        bool flagRight = false;
        
        if(root->left) {
            if(isDeadEndLeaf(root->left,root->data,lowerBound)) return true;
        }
        if(root->right) {
            if(isDeadEndLeaf(root->right,upperBound,root->data)) return true;
        }
        if(!root->left && !root->right) {
            // for left -> upperbound = root->data
            // for right -> upperbound = upperBound
            
            // check left
            
            int j = root->data;
            while(j > lowerBound && s.find(j) != s.end()) {
                j--;
            }
            
            if(j != lowerBound) return false;
            
            // check right
            j = root->data;
            
            while(j < upperBound && s.find(j) != s.end()) {
                j++;
            }
            
            if(j != upperBound) return false;
            
            
            return true;
        }
        
        return false;
        
        
    }
  public:
    bool isDeadEnd(Node *root) {
        s.clear();
        return isDeadEndLeaf(root,INT_MAX,0);
    }
};

