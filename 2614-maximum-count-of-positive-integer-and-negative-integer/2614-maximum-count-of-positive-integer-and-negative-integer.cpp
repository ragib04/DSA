class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
       int neg = binarysearch(nums, 0, n);  //3
       int pos = n - binarysearch(nums, 1, n) ; //7-5= 2
       return max(neg, pos);
    }

    int binarysearch(vector<int> &nums, int target, int n){
        int s = 0, e = n-1;
        int res = n; // why n? bcz corner case if whole arr is 0 then return n ans n-n = 0; so return ans 0 
        while(s<=e){
            int mid = (s+e)/2;// neg -3 1 pos 3 5
            if(nums[mid] < target){
                s = mid+1; // 2 pos 4 5
            }
            else{
                res = mid;  // 3pos = 5
                e = mid-1;// 2 pos - 4
            }
        }
        return res;
    }
};