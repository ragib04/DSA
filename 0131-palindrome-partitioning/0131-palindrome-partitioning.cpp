class Solution {
public:
bool ispalindrome(int l, string &s, int r){
    while(l<=r){
        if(s[l] != s[r]) return false;
        l++;r--;
    }
    return true;
}
void solve(int idx, vector<string>&path, vector<vector<string>>&res, string &s){
    if(idx == s.size()){
        res.push_back(path);
        return;
    }

    for(int i = idx; i<s.size(); i++){
        if(ispalindrome(idx, s, i)){
            path.push_back(s.substr(idx, i-idx+1));
            solve(i+1, path, res, s);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> res;
        solve(0, path, res, s);
        return res;
    }
};