class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if(nums.size() == 1) return 1;
        int maxele = *max_element(begin(nums), end(nums))+k;

        vector<int> freq(maxele+1);
        for(int &num: nums){
            freq[num]++;
        }
        //cummulative sum of frq
        for(int i = 1; i<=maxele; i++){
            freq[i] += freq[i-1];
        }
        int res = 0;
        for(int target = 0; target<maxele; target++){
            if(freq[target] == 0) continue;

            int leftNum = max(0, target-k);
            int rightNum = min(maxele, target+k);

            int totalcnt = freq[rightNum] - ( leftNum>0? freq[leftNum-1] : 0);

            int targetcnt = freq[target] - (target>0? freq[target-1] : 0);

            int needconversion = totalcnt-targetcnt;

            int possibleconv = targetcnt + min(needconversion, numOperations);

            res = max(res, possibleconv);
        }
        return res;
    }
};