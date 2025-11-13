class Solution {
public:
    int maxOperations(string s) {
        int cnt1 = (s[0] == '1');
        int ans = 0;

        for(int i = 1; i<s.length(); i++){
            if(s[i] == '1') cnt1++;
            else if(s[i-1] == '1') ans += cnt1;

        }
        return ans;
    }
};

/*
class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int i = 0, cnt = 0;
        while(i+1<n){
            bool flag = false;
            if(s[i] == '1' && s[i+1] == '0'){
                int j = i+2;
                if(i+1 == n-1){
                    swap(s[i], s[i+1]);
                    cnt++;
                    flag = true;
                }
                
                else while(j<n){
                if(s[j] == '1'){
                    swap(s[i], s[j-1]);
                    cnt++;
                    flag = true;
                    break;
                }
                else j++;
                
                }


            }
            if(flag == true && i-1>=0){
                if(s[i-1] == '1'){
                    i = i-1;
                }
                
            }
            else i++;
            
        }
        return cnt;
    }
};

*/