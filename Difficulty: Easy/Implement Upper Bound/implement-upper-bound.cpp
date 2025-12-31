class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int s = 0, e = n-1;
        int ans = n;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]>target){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};
