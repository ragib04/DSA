class Solution {
public:
vector<int> freq{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int backtrack(int n , int curr, int cnt){
    if(cnt == 0){
        for(int digit = 1; digit<=9; digit++){
            if(freq[digit] != 0 && freq[digit] != digit) return 0;
        }
        return curr>n ? curr: 0;
    }
    int res = 0;
    for(int d = 1; d<=9; d++){
        if(freq[d] != 0 && freq[d]<=cnt){
            freq[d]--;
            res = backtrack(n, curr*10+d, cnt-1);
            freq[d]++;
        }
        if(res != 0) break;
    }
    return res;
}
    int nextBeautifulNumber(int n) {
        int numDigit = to_string(n).length();

        int result = backtrack(n, 0, numDigit);
        if(result == 0){
            result = backtrack(n, 0, numDigit+1);
        }
        return result;
    }
};

/*
class Solution {
public:
bool balanced(int num){
    vector<int> freq(10);
    while(num>0){
        int digit = num%10;
        freq[digit]++;
        num /= 10;

    }
    for(int i = 0; i<10; i++){
        if(freq[i] != 0 && freq[i] !=  i) return false;
    }
    return true;
}
    int nextBeautifulNumber(int n) {
        for(int num = n+1; num<= 1224444; num++){
            if(balanced(num)) return num;
        }
        return 0;
    }
};
*/