class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1);
        for(int i = 0; i<=n; i++){
            int cnt = 0, x = i;
            while(x != 0){
                cnt += x%2;
                x = x/2;
            }
            arr[i] = cnt;
        }
        return arr;
    }
};