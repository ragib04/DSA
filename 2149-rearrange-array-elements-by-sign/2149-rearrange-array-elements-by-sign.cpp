class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> pos, neg;
        for(int i = 0; i<size; i++){
            if(nums[i] >= 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);

        }
        int i = 0, p = 0,  n= 0;
        while(i<size){
            nums[i] = pos[p];
            i++;p++;
            nums[i] = neg[n];
            i++; n++;
        }
        
        return nums;
    }
};