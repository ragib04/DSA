class Solution {
public:
    int minOperations(string s) {
        int cnt = 0, n = s.length();
        for(int i = 0; i<n; i++){
            cnt += (s[i] ^ i) & 1;

        }
        return min(cnt, n-cnt);
    }
};