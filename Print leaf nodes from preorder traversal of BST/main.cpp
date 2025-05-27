class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        if(preorder.size() == 1) return preorder;
        
        vector<int> t1;
        vector<int> t2;
        int root = preorder[0];
        
        for(int i = 1;i<preorder.size();i++) {
            if(preorder[i] < root) t1.push_back(preorder[i]);
            else t2.push_back(preorder[i]);
        }
        
        vector<int> l;
        vector<int> r;
        
        if(t1.size() != 0) l = leafNodes(t1);
        if(t2.size() != 0) r = leafNodes(t2);
    
        vector<int> merged(l.size()+r.size());
        
        merge(begin(l),end(l),begin(r),end(r),begin(merged));
        
        return merged;
    }
};