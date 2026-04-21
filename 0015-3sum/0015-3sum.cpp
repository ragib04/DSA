class Solution {
public:
/*
sort arr
pick n1 ele found remaning two ele n2 n3 in remaning arr
        >> for n2 n3 apply two sum on remaning part of the arr using two pointer
add into ans
*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

      for(int i = 0; i<n; i++){
            
            if(i>0 && nums[i] == nums[i-1]) continue;
            int n1 = -(nums[i]);
            int j = i+1, k = n-1;
    // Two sum
            while(j<k){
                if(nums[j]+nums[k]>n1) k--;
                else if(nums[j]+nums[k]<n1){
                    j++;
                }
                else{
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--; 
                }
                
            }
            
        }
        return ans;
    }
};