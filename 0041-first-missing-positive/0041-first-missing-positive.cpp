class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num: nums){
            mpp[num]++;
        }
        int i =1;
        while(i){
            if(mpp.find(i) != mpp.end()) i++;
            else break;
        }
        return i;
    }
};