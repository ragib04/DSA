class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26], maxi1 = 0, maxi2 = 0;
        for(char c: s){
            int i = c - 'a';
            freq[i]++;
            if(c == 'a' || c == 'i' || c == 'e' || c == 'o' || c=='u'){
                maxi1 = max(maxi1, freq[i]);

            }
            else{
                maxi2 = max(maxi2, freq[i]);
            }
        }
        return maxi1+maxi2;
    }
};