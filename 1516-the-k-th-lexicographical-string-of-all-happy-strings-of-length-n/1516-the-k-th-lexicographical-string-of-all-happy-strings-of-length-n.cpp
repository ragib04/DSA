class Solution {
public:

void solve(int n, string &path, string &res, int k, int &cnt){
    //base case
    if(path.length() == n){
        cnt++;
        if(cnt == k){
            res = path;
        
        }
        
        return;
    }
    for(char ch = 'a'; ch<='c'; ch++){
        if(!path.empty() &&path.back() == ch) continue;
        //do
        path.push_back(ch);
        //explore
        solve(n, path, res, k, cnt);
        //undo
        path.pop_back();
    }
}
    string getHappyString(int n, int k) {
        string path = "";
        string res = "";
        int cnt = 0;
        solve(n, path, res, k, cnt);
        return res;
    }
};