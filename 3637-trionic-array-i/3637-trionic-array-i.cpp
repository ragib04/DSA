class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
    
        while(i+1<n && nums[i]<nums[i+1]){
            i++;
        }
        
        if(i == n-1 || i == 0) return false;
        int p = i;
        while(i+1<n && nums[i]>nums[i+1]){
            i++;
        }
        if(i == n-1 || i == p) return false;
       
        while(i+1 < n && nums[i]<nums[i+1]){
            i++;
        }
        return i == n-1;
        
    
    }
};