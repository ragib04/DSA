class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int res = INT_MAX;
        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);

            if(mp[nums[i]].size()>=3){
                vector<int> &vec = mp[nums[i]];
                int size = vec.size();
                int k = vec[size-3];
                res = min(res, (i-k));
            }
        }
        return res == INT_MAX ? -1 : 2*res;

    }
};