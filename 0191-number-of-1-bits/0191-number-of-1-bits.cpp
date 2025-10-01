class Solution {
public:
    int hammingWeight(int n) {
        // app------>1
        // int cnt = 0;
        // while(n !=0){
        //     n = (n & (n-1));
        //     cnt++;
        // }
        // return cnt;

        //app -->> 2

        // int cnt = 0;
        // for(int i = 31; i>=0; i--){
        //     if((n>>i) &1 == 1) cnt++;
        // }
        // return cnt;


        //App------>3  MATHS APP;
        // int cnt = 0;
        // while(n != 0){
        //     cnt += n%2;
        //     n /= 2;
        // }
        // return cnt;


        // App-------> 4  Built in Function
        return __builtin_popcount(n);

    }
};