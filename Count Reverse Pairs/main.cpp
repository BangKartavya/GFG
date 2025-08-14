class Solution {
  private:
    void mergeSort(std::vector<int>& arr, int left, int right, int& count) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            mergeSort(arr, left, mid, count);
            mergeSort(arr, mid + 1, right, count);
            
            merge(arr, left, mid, right, count);
        }
    }

    void merge(std::vector<int>& arr, int left, int mid, int right, int& count) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays to store the two halves
        std::vector<int> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] > 2 * static_cast<long long>(rightArr[j])) {
                count += (n1 - i);
                j++;
            } else {
                i++;
            }
        }

        i = 0;
        j = 0;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }

        while (i < n1) {
            arr[k++] = leftArr[i++];
        }

        while (j < n2) {
            arr[k++] = rightArr[j++];
        }
    }

  public:
    int countRevPairs(std::vector<int>& arr) {
        // Initialize a variable to store the count of reverse pairs
        int count = 0;
        int n = arr.size();
        
        mergeSort(arr, 0, n - 1, count);
        
        return count;
    }

};