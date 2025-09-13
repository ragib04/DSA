class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        int open = 0;
        for(char c: s){
            if(c == '('){
                
                if(open>0) str += c;
                open++;
            }
            else{ 
                open--;
                if(open>0)
                    str += c;
            }
        }
        return str;
    }
};