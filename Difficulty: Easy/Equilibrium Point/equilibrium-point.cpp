class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            
        }
        int lsum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum -= arr[i];
            if(sum == lsum) return i;
            
            lsum += arr[i];
        }
        return -1;
    }
};