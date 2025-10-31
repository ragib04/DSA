class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = -1, seclargest = -1;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]>largest){
                largest = arr[i];
            }
            
        }
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]>seclargest && arr[i] != largest){
                seclargest = arr[i];
            }
        }
        return seclargest;
    }
};