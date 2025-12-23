class Solution {
private:
    vector<int> arr;
    int n;
    
    int minIdx() {
        int s = 0;
        int e = n-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(arr[mid] < arr[mid-1] && arr[mid] < arr[mid+1]) return mid;
            
            if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]) s = mid+1;
            
            if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) {
                if(arr[mid] < arr[0]) {
                    e = mid-1;
                }
                else s = mid+1;
            }
            
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid+1;
        }
        
        return -1;
    }
public:
    int countLessEqual(vector<int>& arr, int x) {
        this->arr = arr;
        n = arr.size();
        
        if(arr[0] < arr[n-1]) {
            return upper_bound(begin(arr),end(arr),x)-begin(arr);
        }
        
        int piv = minIdx();
        
        int countLeft = upper_bound(begin(arr),begin(arr)+piv,x)-begin(arr);
        int countRight = upper_bound(begin(arr)+piv,end(arr),x)-(begin(arr)+piv);
        
        return countLeft + countRight;
    }
};