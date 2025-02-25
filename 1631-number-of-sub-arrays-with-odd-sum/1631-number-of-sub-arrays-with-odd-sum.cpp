class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int oddcnt = 0, evencnt = 1;
        int sum = 0, ans = 0;
        for(int num: arr){
            sum += num;

            if(sum%2 == 0){
                ans = (ans+oddcnt)%MOD;
                evencnt++;
            }
            else{
                ans = (ans+evencnt)%MOD;
                oddcnt++;
            }
        }
        return ans;
    }
};