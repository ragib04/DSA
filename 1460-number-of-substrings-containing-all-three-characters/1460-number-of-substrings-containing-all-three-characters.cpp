class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int ans = 0;
        int i = 0;
        int j= 0;
        while(j<n){
          //  char ch = s[j];
            mp[s[j]]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                ans += n-j;

                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};