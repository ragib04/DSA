class Solution {
public:
int n;
void solve(string tiles, vector<bool> &used, unordered_set<string> &ans, string &path){
    ans.insert(path);

    for(int i = 0; i<n; i++){
        if(used[i] == true) continue;

        used[i] = true;
        path.push_back(tiles[i]);
        solve(tiles, used, ans, path);

        //undo
        used[i] = false;
        path.pop_back();
    }
}

    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<bool> used(n, false);
        unordered_set<string> ans;
        string path = " ";
        solve(tiles, used, ans, path);
        return ans.size()-1; // -1 ? bcz it ans store a empty path 

    }
};