// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> nums = arr; //[20,15,25,2,,98,6]
        sort(nums.begin(), nums.end());
        unordered_map<int, int> rankArr;
        int rank = 1;
        for(auto num: nums){
            if(rankArr.find(num) == rankArr.end()){
            rankArr[num] = rank;
            rank++;
            }
        }
        vector<int> res;
        for(auto num: arr){
            res.push_back(rankArr[num]);
        }
        
        return res;
    }
};
// [2,2,6,15,20,26,98]
