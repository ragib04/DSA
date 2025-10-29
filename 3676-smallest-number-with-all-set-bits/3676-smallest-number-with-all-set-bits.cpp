class Solution {
public:
    int smallestNumber(int n) {
       // set bit are 1 3 7 15 31 all the no are prev*2+1
       int x = 1;
       while(x<n){
        x = x*2+1;
       }
       return x;
    }
};