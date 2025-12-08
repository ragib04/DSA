class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
       for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1;k<=n; k++){
                if(sqrt((i*i) + (j*j)) == k) cnt++;
            }
        }
       }
       return cnt;
    }
};