class Solution {
public:
int mod = 1000000007;
    int numSub(string s) {
        int cnt = 0, ans = 0;
        for(auto it: s){
            if(it == '1') cnt++;
            else cnt = 0;

            ans = (ans+cnt) % mod;
        }
        return ans;
    }
};