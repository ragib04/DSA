class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;

       stringstream ss(s);
        string token;
        int cntword = 0;
        int i = 0;
        int n = pattern.size();
        while(ss >> token){
            cntword++;
            if(i == n) return false;
            if(charToIndex[pattern[i]] != wordToIndex[token]) return false;

            charToIndex[pattern[i]] = i+1;
            wordToIndex[token] = i+1;

            i++;
        }
        if(cntword != n || i != n) return false;
        else return true;
    }
};