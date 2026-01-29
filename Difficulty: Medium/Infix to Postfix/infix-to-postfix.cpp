class Solution {
  public:
  int pref(char &c){
      if(c == '^') return 3;
      else if(c == '*' || c == '/') return 2;
      else if(c == '+' || c == '-') return 1;
      else return -1;
      
  }
    string infixToPostfix(string& s) {
        // code here
        string res;
        stack<char>st;
        
        
        
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(s[i] >= 'a' && s[i]<='z' || s[i] >= 'A' && s[i] <= 'Z' ||s[i] >= '1' && s[i] <= '9'){
                res += s[i];
            }
            else if(s[i] == '(') st.push(c);
            else if(c == ')'){
                while(st.top() != '('){
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && 
                (pref(c)<pref(st.top()) || 
                pref(c) == pref(st.top()) && c != '^')){
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
            
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};
