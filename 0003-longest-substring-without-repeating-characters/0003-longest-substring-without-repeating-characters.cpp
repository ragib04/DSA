class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i =0, j =0;
        if(n == 0) return 0;
        unordered_map<char, int> mp;
        int ans = 1;
        while(j<n){ /// O(n)
            if(mp.find(s[j]) != mp.end()){
                ans = max(ans, j-i);
                
                i = max(i, mp[s[j]]+1); // if dup is within window otherwise ignore
                
            }
            mp[s[j]] = j;
            j++;
        }
        ans = max(ans, j-i);
        return ans;
    }
};