class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(st.empty()) return false;
            else if(s[i] == '}'){
                if(st.top() == '{'){
                    st.pop();
                    continue;
                } 
                else return false;
            }
            else if(s[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                    continue;
                }
                else return false;
            }
            else if(s[i] == ']'){
                if(st.top() == '['){
                    st.pop();
                    continue;
                }
                return false;
            }

            
            
        }
        if(st.empty()) return true;
        return false;
    }
};