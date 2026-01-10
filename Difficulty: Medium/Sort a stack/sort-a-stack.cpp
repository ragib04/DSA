class Solution {
  public:
  void stinsert(stack<int> &st, int ele){
      if(st.empty() || st.top()<=ele){
          st.push(ele);
          return;
      }
      int val = st.top();
      st.pop();
      stinsert(st, ele);
      st.push(val);
      return;
  }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty() || st.size() == 1) return;
        int top = st.top();
        st.pop();
        sortStack(st);
        stinsert(st, top);
    }
};
