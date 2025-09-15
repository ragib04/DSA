class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        // int i = 0;
        int n = text.size();
       
        bool flag = 0;
        unordered_map<char, int> mp;
        for(auto c: brokenLetters){
            mp[c]++;
        }
        for(int i = 0; i<n; i++){
            
            if(mp[text[i]]>0){
                flag = 1;
                
            }
            if(text[i] == ' ' || i== n-1) {
                if(flag == 0){
                    cnt++;
                   
                }
                flag = 0;
            }
            
        }
        return cnt;
    }
};