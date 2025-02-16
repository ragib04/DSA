class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        if(s.size() == 1 && k==1) return true;
    
        int cnt = 1;
        for(int i = 1; i<s.length(); i++){
            if(s[i] != s[i-1] && cnt == k)return true;
            
            
                if(s[i] != s[i-1]) cnt = 0;
                cnt++;
            }
        
        return (cnt == k);
    }
};