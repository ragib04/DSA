class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int maxc = 0, maxv =0;
        for(char c: s){
            if(isvowel(c)){
                mp[c]++;
                maxv = max(maxv, mp[c]);
            }
            else{
                mp[c]++;
                maxc = max(maxc, mp[c]);
            }
        }
        return maxc+maxv;
    }
    bool isvowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};