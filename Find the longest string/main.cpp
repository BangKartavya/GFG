class TrieNode {
    public:
        char value;
        bool isEnd;
        TrieNode* children[26];
        
        TrieNode(char val) {
            value = val;
            isEnd = false;
            for(int i = 0;i<26;i++) children[i] = nullptr;
        }
};

class Trie {
    private:
        TrieNode* root;
        
    public:
        Trie() {
            root = new TrieNode(-1);
        }
    
        void insert(string& s) {
            TrieNode* currNode = root;
            
            for(char& ch: s) {
                if(currNode->children[ch-'a'] == nullptr) {
                    currNode->children[ch-'a'] = new TrieNode(ch);
                }
                
                currNode = currNode->children[ch-'a'];
            }
            
            currNode->isEnd = true;
        }
        
        bool find(string& s) {
            TrieNode* currNode = root;
            
            for(char& ch: s) {
                if(currNode->children[ch-'a'] == nullptr) return false;
                
                currNode = currNode->children[ch-'a'];
            }
            
            return currNode->isEnd;
        }
};

class Solution {
  public:
    string longestString(vector<string> &arr) {
        sort(arr.begin(), arr.end());
        unordered_map<string, bool> map;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i].size() == 1)
                map[arr[i]] = true;
            
            else {
                string temp = arr[i];
                temp.pop_back();
                
                if(map[temp] == true)
                    map[arr[i]] = true;
                else 
                    map[arr[i]] = false;
            }
        }
        string ans = "";
        for(int i=0; i<arr.size(); i++){
            if(map[arr[i]] == true && arr[i].size() > ans.size())
                ans = arr[i];
        }
        
        return ans;
    }
};