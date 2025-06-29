class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        for (char& ch : s) {
            mpp[ch]++;
        }
        int result = 0;
        bool countfreq = false;
        for (auto& it : mpp) {
            if (it.second % 2 == 0) {
                result = result + it.second;
            } else {
                result = result + it.second - 1;
                countfreq = true;
            }
        }
        if (countfreq) {
            result++;
        }
        return result;
    }
};