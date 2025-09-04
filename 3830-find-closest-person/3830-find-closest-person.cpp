class Solution {
public:
    int findClosest(int x, int y, int z) {
        // if((x==z) && (y == z)) return 0;
        // if((x == z)) return 1;
        // if(y == z) return 2;
        // int p1 = abs(x-z);
        // int p2 = abs(y-z);
        // if(p1<p2) return 1;
        // if(p1>p2) return 2;
        // return 0;
       
        return abs(x-z) == abs(y-z)?0: abs(x-z)>abs(y-z)?2:1;

    }
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              