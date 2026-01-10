class Solution {
  public:
  void insert(stack<int> &st, int ele){
      if(st.empty()){
          st.push(ele);
          return;
      }
      int top = st.top();
      st.pop();
      insert(st, ele);
      st.push(top);
      return;
  }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty() ) return;
        int top = st.top();
        st.pop();
        reverseStack(st);
        insert(st, top);
    }
};