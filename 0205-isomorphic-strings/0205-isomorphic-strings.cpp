class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int len = s.size();
        for(int i =0; i<len; i++){
            if(mp1[s[i]] != mp2[t[i]]){
                return false;
            }
            mp1[s[i]] = i+1;
            mp2[t[i]] = i+1;
        }
        return true;
    }
};