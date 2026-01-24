class Solution {
  public:
  void func(int n, vector<string> &ans, string &s){
      if(n == 0){
          ans.push_back(s);
          return;
      }
      s.push_back('0');
     func(n-1, ans,s);
     s.pop_back();
     s.push_back('1');
     func(n-1, ans, s);
     s.pop_back();
  }
    vector<string> binstr(int n) {
        // code here
        vector<string> ans;
        string s;
        func(n, ans, s);
        return ans;
    }
};