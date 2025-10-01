class Solution {
public:
// t.c -> O(numBottles)
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;
        while(numBottles >= numExchange){
            consumed += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }
        return consumed+numBottles;
    }
};

/*

T.C -> O(log(N))
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
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
*/