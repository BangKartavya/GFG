/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  private:
    Node* getMiddle(Node* head) {
        if(!head) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* merge(Node* left,Node* right) {
        if(!left) return right;
        if(!right) return left;
        
        Node* result = nullptr;
        
        if(left->data <= right->data) {
            result = left;
            result->next = merge(left->next,right);
        }
        else {
            result = right;
            result->next = merge(left,right->next);
        }
        
        return result;
    }
  public:
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        
        Node* middle = getMiddle(head);
        Node* nxt = middle->next;
        middle->next = nullptr;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(nxt);
        
        return merge(left,right);
        
    }
};