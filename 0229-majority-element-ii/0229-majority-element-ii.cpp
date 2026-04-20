class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<int> ans;
       int n = nums.size();
       int i = 0;
       for(int j = 0; j<nums.size(); j++){
        if(nums[i] != nums[j]){
            if((j-i) > n/3) ans.push_back(nums[i]);
            i = j;
        }

       }
       if(n-i>n/3) ans.push_back(nums[i]);

       
       return ans;
    }
};