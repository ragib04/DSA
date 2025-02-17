class Solution {
public:
int n;
void solve(string &tiles, vector<bool> &used, unordered_set<string> &ans, string curr){

    ans.insert(curr);

    for(int i = 0; i<n; i++){
        if(used[i]) continue;

        used[i] = true;
        curr.push_back(tiles[i]);
        solve(tiles, used, ans, curr);

        used[i] = false;
        curr.pop_back();
    }

}

    int numTilePossibilities(string tiles) {
      n = tiles.size();
        vector<bool> used(n, false);
        unordered_set<string> ans;
        string curr = " ";
        solve(tiles, used, ans, curr);
        return ans.size()-1;
    }
};