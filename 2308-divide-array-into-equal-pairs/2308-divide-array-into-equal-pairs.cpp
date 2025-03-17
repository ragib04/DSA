class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n= nums.size();
        int i = 0;
        while(i<n){
            int val = nums[i];
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(nums[j] == val) cnt++;
            }
            i++;
            if(cnt%2 != 0) return false;
        }
        return true;
    }
};