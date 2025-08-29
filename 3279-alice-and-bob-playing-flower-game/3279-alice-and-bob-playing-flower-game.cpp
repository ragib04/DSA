class Solution {
public:

    long long flowerGame(int n, int m) {
       long oddx = (n+1)/2;
       long evenx = n/2;

       long oddy = (m+1)/2;
       long eveny = m/2;

       return (oddx*eveny)+(evenx*oddy);
    }
};