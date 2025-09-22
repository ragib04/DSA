class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        int maxi = *max_element(freq.begin(), freq.end());
        int res = 0;
        for(int i = 0; i<101; i++){
            if(freq[i] == maxi) res += freq[i];
        }
        return res;
    }
};



/*
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int maxi = 0;

        for(auto i:mp){
            if(i.second>= maxi){
                maxi = i.second;
            }
        }
        int cnt = 0;
        for(auto it: mp){
            if(it.second == maxi){
                cnt+=maxi;
            }
        }
        return cnt;
    }
};
*/