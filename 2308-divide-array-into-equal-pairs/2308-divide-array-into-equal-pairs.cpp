class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp(n/2);
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
       for(auto &it: mp){
        int val = it.second;
        if(val % 2 != 0) return false;
       }
       return true;
    }
};