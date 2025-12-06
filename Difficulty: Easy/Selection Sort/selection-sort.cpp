class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i<n; i++){
            int mi_idx = i;
            for(int j = i+1; j<n; j++){
                if(arr[j]<arr[mi_idx]) mi_idx = j;
            }
            swap(arr[i], arr[mi_idx]);
        }
    }
};