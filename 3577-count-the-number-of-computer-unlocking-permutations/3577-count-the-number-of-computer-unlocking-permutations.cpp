class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod = 1e9+7;
        long ans = 1;
        int n = complexity.size();
        for(int i = 1; i<n; i++){
                if(complexity[i]<=complexity[0]) return 0;
                
            }
        for(int i=1; i<n;i++){
            ans =  (i * ans)%mod;
        }
        return (int)ans;
    }
};