class Solution {
  public:
  void insert(stack<int> &st, int ele){
      if(st.empty() || st.top() < ele){
          st.push(ele);
          return;
      }
      
      int top = st.top();
      st.pop();
      insert(st, ele);
      st.push(top);
      return;
      
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




/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};


*/

/* The below method sorts the stack s 
you are required to complete the below method */

// void insert(stack<int> &s, int temp){
//     if(s.size() == 0 || s.top()<= temp){
//         s.push(temp);
//         return;
//     }
//     int val = s.top();
//     s.pop();
//     insert(s, temp);
//     s.push(val);
//     return;
// }
// void SortedStack :: sort()
// {
//   //Your code here
//   if(s.size() == 1) return;
   
//   int temp = s.top();
//   s.pop();
//   sort();
//   insert(s, temp);
//   return;
// }
