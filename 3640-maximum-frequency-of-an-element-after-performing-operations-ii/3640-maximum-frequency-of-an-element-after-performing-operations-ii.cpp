// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k, int numOperations) {
//         if(nums.size() == 1) return 1;
//         int maxele = *max_element(begin(nums), end(nums))+k;
//         map<int, int> diff;
//         unordered_map<int, int> freq;

       
//         for(int i = 0; i<nums.size(); i++){
//             freq[nums[i]]++;
//             int l = max(nums[i]-k, 0);
//             int r = min(nums[i]+k, maxele);
//             diff[l]++;
//             diff[r+1]--;
//             diff[nums[l]] += 0;

//         }
//         int cumsum = 0;
//         int res = 1;
//         for(auto it = diff.begin(); it != diff.end(); it++){
//            int target = it->first;
//            it->second += cumsum; 

           

//             int totalcnt = freq[target];

//             int targetcnt = freq[target] - (target>0? freq[target-1] : 0);

//             int needconversion = it->second - targetcnt;

//             int possibleconv =  min(needconversion, numOperations);

//             res = max(res, possibleconv+targetcnt);
//             cumsum = it->second;
//         }
//         return res;
//     }
// };


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;
        map<int, int> diff;   
        unordered_map<int, int> freq;

        //O(nlogn)
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, maxVal);

            diff[l]++;
            diff[r+1]--;

            diff[nums[i]] += 0;
        }


        int result = 1;
        int cumSum = 0;
        for(auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;
            it->second += cumSum;

            int targetFreq     = freq[target];
            int needConversion = it->second - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            result = max(result, targetFreq + maxPossibleFreq);

            cumSum = it->second;
        }

        return result;
    }
};