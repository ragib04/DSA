class Solution {
public:
void func(int n, int open, int close, vector<string> &ans, string path){
    if(path.size()==2*n){
        ans.push_back(path);
        return;
    }
    if(open<n) func(n, open+1, close, ans, path+'(');
    if(close<open) func(n, open, close+1, ans, path+')');
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        func(n, 0, 0, ans, path);
        return ans;
    }
};