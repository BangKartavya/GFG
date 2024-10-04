//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
        int data;
        struct Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
};

// Function to print nodes in a given circular linked list
void printList(struct Node* head) {
    if(head != NULL) {
        struct Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}

// } Driver Code Ends
class Solution {
    public:
        // Function to reverse a circular linked list
        Node* reverse(Node* head) {
            // code here
            if(head == NULL || head->next == head) {
                return head; // Empty list or single node, no need to reverse
            }

            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;

            // First, store the original head
            Node* originalHead = head;

            while(curr->next != originalHead) { // Traverse until we are about to loop back
                next = curr->next;              // Store the next node
                curr->next = prev;              // Reverse the pointer
                prev = curr;                    // Move prev forward
                curr = next;                    // Move curr forward
            }

            // Handle the final node (when curr == originalHead)
            next = curr->next;
            curr->next = prev;
            head->next = curr; // Make the last node point to the new head
            head = curr;

            return head;
        }

        // Function to delete a node from the circular linked list
        Node* deleteNode(Node* head, int key) {
            // code here
            if(head == NULL) {
                return NULL; // Empty list, nothing to delete
            }

            Node* curr = head;
            Node* prev = NULL;

            // Special case: If head node is to be deleted
            if(head->data == key) {
                // If there's only one node in the list
                if(head->next == head) {
                    delete head;
                    return NULL;
                }

                // Find the last node in the list to update its next pointer
                Node* last = head;
                while(last->next != head) {
                    last = last->next;
                }

                // Update the last node's next pointer and delete the head
                last->next = head->next;
                Node* temp = head;
                head = head->next;
                delete temp;
                return head;
            }

            // Traverse the list to find the node with the given key
            while(curr->next != head) { // Stop if we return to the head
                if(curr->next->data == key) {
                    Node* temp = curr->next;
                    curr->next = curr->next->next; // Unlink the node
                    delete temp;
                    return head;
                }
                curr = curr->next;
            }

            // If key wasn't found
            return head;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while(ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;
        for(int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends