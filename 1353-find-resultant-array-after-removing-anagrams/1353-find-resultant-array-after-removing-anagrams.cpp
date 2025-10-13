class Solution {
public:

bool isanagrams(string st1, string st2) {
        if (st1.size() != st2.size()) return false;
        
        // unordered_map<char, int> mp;
        // for (char c : st1) mp[c]++;
        // for (char c : st2) {
        //     if (--mp[c] < 0) return false;
        // }
        // return true;
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());

        return st1 == st2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        if(words.size() <=1) return words;
        ans.push_back(words[0]);
       for(int i = 1; i<words.size(); i++){
            if(!isanagrams(words[i], words[i-1])) ans.push_back(words[i]);
       } 
       return ans;
    }
};