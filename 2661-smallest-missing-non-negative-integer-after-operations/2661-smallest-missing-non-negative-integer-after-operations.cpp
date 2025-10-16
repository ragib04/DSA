class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++){
            int x = nums[i];
            x = (x%value);
            if(x<0) x = value-abs(x);
           
            freq[x]++;
        }
        int res = 0;
        while(1){
            int num = res%value;
            if(num<0) num = value-num;
            if(!freq[num]) return res;
            else{
                freq[num]--;
            }
            res++;
        }
        return 0;
    }
};