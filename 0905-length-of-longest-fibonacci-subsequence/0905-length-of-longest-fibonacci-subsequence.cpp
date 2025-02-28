/*
class Solution {
public:

int solve(int j, int k, vector<int> &arr, unordered_map<int, int> &mp){
    int target = arr[k] - arr[j];

    if(mp.count(target) && mp[target] < j){ //i<j<k
        int i = mp[target];
        return solve(i, j, arr, mp) +1;
    }
    return 2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]] = i;
        }
        int maxlen = 0;
        for(int j = 1; j<n; j++){
            for(int k = j+1; k<n; k++){
                int len = solve(j, k, arr, mp);
                if(len>=3){
                    maxlen = max(len, maxlen);
                }
            }
        }
        return maxlen;
    }
};
*/
//.
/*   Memoization---------->
class Solution {
public:

int solve(int j, int k, vector<int> &arr, unordered_map<int, int> &mp, vector<vector<int>> &t){

    if(t[j][k] != -1) return t[j][k];
    int target = arr[k] - arr[j];

    if(mp.count(target) && mp[target] < j){ //i<j<k
        int i = mp[target];
        return t[j][k] = solve(i, j, arr, mp, t) +1;
    }
    return t[j][k] = 2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> t(n, vector<int> (n,-1));
        for(int i = 0; i<n; i++){
            mp[arr[i]] = i;
        }
        int maxlen = 0;
        for(int j = 1; j<n; j++){
            for(int k = j+1; k<n; k++){
                int len = solve(j, k, arr, mp, t);
                if(len>=3){
                    maxlen = max(len, maxlen);
                }
            }
        }
        return maxlen;
    }
};

*/

//         -->BOtom up
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]] = i;
        }
        vector<vector<int>> t(n, vector<int>(n, 2));
        int maxlen = 0;
        for(int j = 1; j<n; j++){
            for(int k = j+1; k<n; k++){
                int target = arr[k] - arr[j];
                if(mp.count(target) && mp[target]< j){
                    int i = mp[target];
                    t[j][k] = t[i][j]+1;
                }
                maxlen = max(maxlen, t[j][k]);
            }
        }
        return maxlen >= 3 ? maxlen : 0;
    }
};