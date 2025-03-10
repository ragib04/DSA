class Solution {
public:
bool isVowel(char &ch){
    return ch == 'a' || ch == 'e' || ch == 'i' ||ch == 'o' || ch == 'u';
}
    long long countOfSubstrings(string word, int k) {
        int n = word.size();

        unordered_map<char, int> mp;
        vector<int> nextCons(n);
        int lastcons = n;
        for(int i = n-1; i>=0; i--){
            nextCons[i] = lastcons;
            if(!isVowel(word[i])){
                lastcons = i;
            }
        }
       
     int i = 0;
        int j = 0;
        long long count = 0;
        int cons = 0;
       
        while(j < n) {
            char ch = word[j];
            if(isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

          
            while(cons > k) {
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            while(i < n && mp.size() == 5 && cons == k) { 
                int idx = nextCons[j]; //next consonant char after jth index
                count += idx - j; 
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};
