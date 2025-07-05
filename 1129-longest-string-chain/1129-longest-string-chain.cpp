class Solution {
public:

    bool checkpossible(string &s1, string &s2){
        if(s1.size() != s2.size() + 1) return false;

        int first = 0, second = 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            } else {
                first++;
            }
        }
        return first == s1.size() && second == s2.size();
    }

    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](const string &a, const string &b){
            return a.length() < b.length();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(checkpossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
