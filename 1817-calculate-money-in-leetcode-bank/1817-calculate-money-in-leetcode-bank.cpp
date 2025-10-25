class Solution {
public:
    int totalMoney(int n) {
        int monday  = 1;
        int total = 0;
        int i = 1;
        int day = 0;
        while(n != 0){
            day++;// 1 2 3 4  5 6 7 0 1 2
            total += i; // 1 3 6 10 15 21 28 31 34 28
            i++; // 2 3 4 5 6 7 3 4
            n--;// 9 8 7 6 5 4 3 2 1
            
            if(day == 7){
                i = monday+1;
                monday += 1;
                day = 0;
            }

        }
        return total;
    }
};