    //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
        
        Node(int key,int value){
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
            
        }
            
    };
    
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> store;
  
    void add(Node* ele){
        Node* nexi = head->next;
        head->next = ele ;
        ele->prev = head;
        ele->next = nexi;
        nexi->prev = ele;
        return;
        
    }
    
    void rem(Node* ele , bool del){
        Node* nexi = ele->next;
        Node* previ = ele->prev;
        previ->next = nexi;
        nexi->prev = previ;
        
        ele->prev = NULL;
        ele->next = NULL;
        if(del)
            delete ele;
        return;
        
    }
    
  
  
  
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        this->capacity = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        
        tail->prev = head;
        head->next = tail;
        
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(store.find(key) != store.end()){
            Node* ele = store[key];
            rem(ele,false);
            add(ele);
            return ele->value;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(store.find(key) != store.end()){
            Node* ele = store[key];
            ele->value = value;
            rem(ele,false);
            add(ele);
            return;
        }
        Node* ele = new Node(key,value);
        add(ele);
        store[key]=ele;
        
        if(store.size() > capacity){
            Node* delNode = tail->prev;
            store.erase(delNode->key);
            rem(delNode,true);
            
        }
        
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends