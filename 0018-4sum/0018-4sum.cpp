class Solution {
public:
vector<vector<int>> ans;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
    for(int i = 0; i<n-3; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        //three sum
        for(int j = i+1; j<n-2; j++){
            
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            
            int k = j+1, l = n-1;
    // Two sum
            while(k<l){
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    

                    while(k<l && nums[k] == nums[k+1]) k++;
                    while(k<l && nums[l] == nums[l-1]) l--;
                    k++;l--;
                }
                else if(sum < target) k++;
                else l--;
                
                
            }
            
        }
    }
    return ans;
    }
};