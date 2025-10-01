class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // return (numBottles*numExchange-1)/(numExchange-1);
        int n = numBottles, x = numExchange;
        int cnt = n;int r = 0;
        while(n>=x){
            r = n%x;
            n = n/x;
            cnt += n;
            n += r;
        }
        return cnt;
    }
};