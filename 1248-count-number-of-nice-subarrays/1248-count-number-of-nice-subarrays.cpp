class Solution {
public:
int atmost(vector<int>& nums, int goal) {
    
        if(goal<0) return 0;
        int cnt = 0;
        int i = 0;
            int odd = 0;
            for(int j = 0; j<nums.size(); j++){
                if(nums[j]%2) odd++;
            
                while(odd>goal){
                    if(nums[i]%2) odd--;
                    i++;

                }
                cnt += (j-i+1);
            
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atmost(nums, k) - atmost(nums,k-1);
    }
};