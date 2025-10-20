class Solution {
public:

void solve(int ind, string &digits,string &temp, unordered_map<char, string> &mp, vector<string> &res){
    if(ind == digits.size()){
        res.push_back(temp);
        return;
    }
    char ch = digits[ind];
    string s = mp[ch];

    for(int i = 0; i<s.length(); i++){
        temp.push_back(s[i]);
        solve(ind+1, digits, temp, mp, res);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp;
        unordered_map<char, string> mp{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

       solve(0, digits, temp, mp, res);
       return res;
       

    }
};