class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<int, int> mp;
        int ans = 0, i = 0;
        int max_freq = 0, windo_len = 0;
        for(int j = 0; j<n; j++){
            mp[s[j]]++;
            max_freq = max(max_freq, mp[s[j]]);
            while((j-i+1) - max_freq > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};