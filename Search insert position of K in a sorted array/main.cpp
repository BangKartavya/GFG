class Solution {
    public:
        int searchInsertK(vector<int>& arr, int k) {
            // code here
            int s = 0;
            int e = arr.size() - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(arr[mid] == k) return mid;
                else if(arr[mid] < k) s = mid + 1;
                else e = mid - 1;
            }

            return s;
        }
};