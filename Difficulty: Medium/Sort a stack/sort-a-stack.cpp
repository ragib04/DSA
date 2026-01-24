class Solution {
  public:
 void insert(stack<int> &st, int ele){
     if(st.empty() || st.top()<ele){
         st.push(ele);
         return;
     }
     int top= st.top();
     st.pop();
     insert(st, ele);
     st.push(top);
 }
    void sortStack(stack<int> &st) {
        // code here
       if(st.empty() || st.size() == 1) return;
       int top = st.top();
       st.pop();
       sortStack(st);
       insert(st, top);
    }
};
