/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        Node* last = head;
        Node* first = head; 
        for(int i = 1;i<k;i++){
            if(last == NULL || first == NULL) return head;
            last = last->next;
            first = first->next;
        }
        if(last == NULL) return head;
        Node* slow = head;
        while(last->next!=NULL) {
            last = last->next;
            slow = slow->next;
        }
        int temp = first->data;
        first->data = slow->data;
        slow->data = temp;
        return head;
    }
};