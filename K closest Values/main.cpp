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

        void inOrder(Node* root) {
            if(!root) return;

            inOrder(root->left);
            result.push_back(root->data);
            inOrder(root->right);
        }

    public:
        vector<int> getKClosest(Node* root, int target, int k) {
            inOrder(root);

            int n = result.size();

            vector<int> res;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            for(int i = 0; i < n; i++) {
                pq.push({abs(target - result[i]), i});
            }

            while(res.size() < k && !pq.empty()) {
                res.push_back(result[pq.top().second]);
                pq.pop();
            }

            return res;
        }
};