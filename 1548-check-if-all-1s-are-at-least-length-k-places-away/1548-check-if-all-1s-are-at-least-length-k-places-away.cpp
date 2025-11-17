class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
    //     int cnt = 0;
    //     bool flag = false;
    //   for(int i = 0; i<nums.size(); i++){
    //     if(nums[i] == 1){
    //         if(cnt<k && flag == true) return false;
    //         cnt = 0;
    //         flag = true;
    //     }
    //     else {
    //         cnt++;  
    //     }
    //   }
    //   return true; 
    int prev_ind = -1e9;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == 1){
            if(i-prev_ind-1<k) return false;
            prev_ind = i;
        }
    }
    return true;
    }
};