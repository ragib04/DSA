class Solution {
public:
    int totalMoney(int n) {
        int monday = 0;
        int cnt = 1;
        int total = 0;
        for(int i = 1; i<=n; i++){
            total += cnt;
            cnt++;
            if(cnt > 7+monday){
                 monday += 1;
                 cnt = 1+monday;
                }         
        }
        return total;
    }

};