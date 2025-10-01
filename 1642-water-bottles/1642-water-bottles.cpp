class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // return (numBottles*numExchange-1)/(numExchange-1);
        int n = numBottles, x = numExchange;
        return n + (n-1)/(x-1);
    }
};