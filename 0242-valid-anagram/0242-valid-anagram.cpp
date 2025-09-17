/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
       sort(s.begin(), s.end());
    sort(t.begin(), t.end());

        return (s==t);
    }
};
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false;
        vector<int> freq(26, 0);
        for(int i = 0; i<n; i++){
            freq[s[i] - 'a']++;

        }
         for(int i = 0; i<n; i++){
            freq[t[i] - 'a']--;

        }
        for(int i = 0; i<26; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};