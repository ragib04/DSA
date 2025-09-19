class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        stack<char> st;
        int cnt  = 0;
        for(char ch: s){
            if(ch == '('){
                cnt++;
            }
            if(ch == ')'){
                maxi = max(cnt, maxi);
                cnt--;
            }
        }
        return maxi;
    }
};