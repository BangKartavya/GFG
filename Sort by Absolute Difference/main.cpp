class Solution {
    private:
        void merge(int s, int mid, int e, vector<int>& arr, int x) {
            vector<int> temp(e - s + 1);

            int i = s;
            int j = mid + 1;
            int idx = 0;

            while(i <= mid && j <= e) {
                if(abs(arr[i] - x) <= abs(arr[j] - x)) {
                    temp[idx++] = arr[i++];
                } else temp[idx++] = arr[j++];
            }

            while(i <= mid)
                temp[idx++] = arr[i++];

            while(j <= e)
                temp[idx++] = arr[j++];

            for(int i = s; i <= e; i++) {
                arr[i] = temp[i - s];
            }
        }
        void mergeSort(int s, int e, vector<int>& arr, int x) {
            if(s < e) {
                int mid = s + (e - s) / 2;

                mergeSort(s, mid, arr, x);
                mergeSort(mid + 1, e, arr, x);
                merge(s, mid, e, arr, x);
            }
        }

    public:
        void rearrange(vector<int>& arr, int x) {
            mergeSort(0, arr.size() - 1, arr, x);
        }
};