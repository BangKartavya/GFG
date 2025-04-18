//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class TrieNode {
  public:
    bool isEnd;
    char val;
    unordered_map<char,TrieNode*> children;
    
    TrieNode(char x) {
        val = x;
        isEnd = false;
    } 
};

class Trie {
  private:
    TrieNode* root;
  public:
    Trie() {
        root = new TrieNode(-1);
    }

    void insert(string &word) {
        TrieNode* currNode = root;
        
        for(char& ch: word) {
            if(currNode->children.find(ch) == currNode->children.end()) {
                currNode->children[ch] = new TrieNode(ch);
            }
            
            currNode = currNode->children[ch];
        }
        
        currNode->isEnd = true;
    }

    bool search(string &word) {
        bool found = true;
        TrieNode* currNode = root;
        
        for(char& ch: word) {
            if(currNode->children.find(ch) == currNode->children.end()) {
                found = false;
                break;
            }
            
            currNode = currNode->children[ch];
        }
        
        return found && currNode->isEnd;
    }

    bool isPrefix(string &word) {
        bool found = true;
        TrieNode* currNode = root;
        
        for(char& ch: word) {
            if(currNode->children.find(ch) == currNode->children.end()) {
                found = false;
                break;
            }
            
            currNode = currNode->children[ch];
        }
        
        return found;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends