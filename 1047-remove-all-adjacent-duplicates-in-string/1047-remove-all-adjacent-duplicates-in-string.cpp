class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(!st.empty() && s[i] == st.top()){
                res.pop_back();
                st.pop();
            }
            else {
                res += s[i];
            
            st.push(s[i]);
            }
        }
        return res;
    }
};