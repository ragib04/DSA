class Solution {
public:
    int countOdds(int low, int high) {
        // int cnt = 0;
        // for(int i = low; i<=high; i++){
        //     if(i%2 != 0) cnt++;
        // }
        // return cnt;
        int total = high-low+1;
        if(total%2 == 0) return total/2;
        else if(low%2 != 0 && high%2 != 0) return total/2+1;
        return total/2;
    }
};