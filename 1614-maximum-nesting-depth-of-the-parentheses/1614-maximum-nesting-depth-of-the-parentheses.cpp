class Solution {
public:
    int maxDepth(string s) {
        int n= s.size();
        int open = 0;
        int cnt = 0;
        int maxi = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                open++;
            }
            else if(open>0 && s[i] == ')'){
                
                maxi = max(maxi, open);
                open--;
                }
            }
            
        
        return maxi;
    }
};