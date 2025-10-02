class Solution {
public:
    int maxBottlesDrunk(int n, int x) {
        int consumed = n;
        int empty = n;
        n = 0;
        while (empty >= x) {
            empty -= x;
            consumed += 1;
            n += 1;
            x++;
        }
        if(empty+n >= x){
            return consumed + 1;
        }
        return consumed;
    }
};