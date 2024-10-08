//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
            int data;
            Node *right, *down;

            Node(int x) {
                data = x;
                right = NULL;
                down = NULL;
            }
};

/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
    public:
          Node* constructLinkedMatrix(vector<vector<int>>& mat) {
                int n = mat.size();
                int m = mat[0].size();
                vector<vector<Node*>> v(n, vector<Node*>(m, NULL));
      

                    for(i n t  j  =  m  - 1; j >= 0; j--) {
                        v[i][ j ]  =  n ew  Node(mat[i][j]);
    

                        if(j + 1 < m) v[i][j]->right  =  v[i][j + 1];
                    }  
                }
    

            }
};

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while(Dp) {
        Rp = Dp;
        while(Rp) {
           cout << Rp->data << " ";
            if(Rp->right)
               cout << Rp->right->data << " ";
            else
               cout << "null ";
            if(Rp->down)
                cout << Rp->down->data << " ";
            else
               cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while(t--) {
        string line;
        getline(cin, line);
        sringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while(ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for(int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
           stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while(ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if(!head) {
            cout << "-1\n";
        } else {
           display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends