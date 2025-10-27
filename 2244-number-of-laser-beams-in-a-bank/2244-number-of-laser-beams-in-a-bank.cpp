class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevcnt = 0;
        for(int i = 0; i<bank.size(); i++){
            int cnt = 0;
            for(int j = 0; j<bank[0].size(); j++){
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt != 0){
            ans= cnt*prevcnt+ans;
            prevcnt = cnt;
            
            }
        }
        return ans;
    }
};