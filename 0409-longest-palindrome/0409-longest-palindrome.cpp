class Solution {
public:
    int longestPalindrome(string s) {
        int n= s.length();
        unordered_map<char, int> mp;

        int result = 0;
        int countoddfreq = 0;

        for(char &ch : s){
            mp[ch]++;

            if(mp[ch] %2 != 0){
                countoddfreq++;

            }
            else{
                countoddfreq--;
            }
        }
        if(countoddfreq > 0){
            return n-countoddfreq+1;
        }
        return n;
        
    }
};