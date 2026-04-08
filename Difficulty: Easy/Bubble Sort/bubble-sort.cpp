class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=i-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};