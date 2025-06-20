class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(auto i : nums){
            mpp[i]++;
        }
        for(auto it: mpp){
            if(it.second > (n/2)) return it.first;
        }
        return -1;
    }
};