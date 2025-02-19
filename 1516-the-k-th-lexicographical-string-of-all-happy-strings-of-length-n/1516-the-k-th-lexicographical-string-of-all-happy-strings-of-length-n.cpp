class Solution {
public:

void solve(int n, string &path, vector<string> &res){
    //base case
    if(path.length() == n){
        res.push_back(path);
        return;
    }
    for(char ch = 'a'; ch<='c'; ch++){
        if(!path.empty() &&path.back() == ch) continue;
        //do
        path.push_back(ch);
        //explore
        solve(n, path, res);
        //undo
        path.pop_back();
    }
}
    string getHappyString(int n, int k) {
        string path = "";
        vector<string> res;
        solve(n, path, res);
        if(res.size()<k) return "";

        return res[k-1];
    }
};