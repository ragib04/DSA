class Solution {
public:

    long long maximumTripletValue(vector<int>& nums) {
        long maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = n-1; j>i; j--){
                int k = i+1;
                while(k<j){
                    maxi = max(maxi, (long(nums[i]-nums[k])*nums[j]));
                    k++;
                }
                
            }
        }
       
        return maxi < 0 ? 0 : maxi;
    }
};