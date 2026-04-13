class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st;
        int sum = 0;
        for(auto it: nums){
            sum += it;
            st.insert(it);
        }
        int sum_1 = 0;
        for(auto it: st){
            sum_1 += it;
        }
        return 2*sum_1 - sum;
    }
};
//14