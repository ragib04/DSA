class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //app 1 mpp
        /*
        class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
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
        */
//app 2 sorting
/*
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        for(int i = 0; i<n; i += 2){
            if(nums[i] != nums[i+1]) return false;
        }
        return true;
    }
};
*/

        //App 3 xor
        sort(nums.begin(), nums.end());
        int n= nums.size();
        for(int i = 1; i<n; i += 2){
            if((nums[i] ^ nums[i-1]) != 0) return false;
        }
        return true;

        /*
        //Two pointer

        class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n= nums.size();
        int i = 0;
        while(i<n){
            int val = nums[i];
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(nums[j] == val) cnt++;
            }
            i++;
            if(cnt%2 != 0) return false;
        }
        return true;
    }
};
        */
    }
};