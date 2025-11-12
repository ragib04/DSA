class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int res = INT_MAX, cnt1 = 0;
        for (int i = 0; i < n; ++i)
            cnt1 += (nums[i] == 1);
        if (cnt1)
            return n - cnt1;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    res = min(res, j - i + n - 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

/*
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int res = INT_MAX;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1) cnt++;
        }
        if(cnt) return n-cnt;
        for(int i = 0; i<nums.size(); ++i){
            int num = nums[i];
            for(int j = i+1; j<nums.size(); ++j){
              
                num = __gcd(num, nums[j]);

                if(num == 1){
                  
                   res = min(res, j+n-2);
                   break;
                }
               
            }
        }
        return res == INT_MAX ? -1 : res;
        

    }
};


*/