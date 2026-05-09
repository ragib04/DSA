class Solution {
  public:
 void insert(stack<int> &st, int ele){
     if(st.empty() || st.top()<ele){
         st.push(ele);
         return;
     }
     int top= st.top();
     st.pop();
     insert(st, ele); // 
     st.push(top);
 }
    void sortStack(stack<int> &st) {
        // code here
       if(st.empty() || st.size() == 1) return;
       int top = st.top();
       st.pop();
       sortStack(st); //n calls
       insert(st, top);
    }
};
//sort stack call -> n
//incert = n ->insert + (n-1) popped + (n-1) pushed ....1 -> O(n)

// t.c= O(n)*o(n) = n^2
//s.c -> O(N) recursion call stack
