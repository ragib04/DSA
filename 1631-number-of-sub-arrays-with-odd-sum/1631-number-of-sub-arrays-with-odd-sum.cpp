class Solution {
public:
int MOD = 1e9+7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int oddcnt = 0, evencnt = 1;
    int sum = 0, cnt = 0;

    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(sum%2 == 0){
            cnt = (cnt+oddcnt)%MOD;
            evencnt++;
        }
        else{
            cnt = (cnt+evencnt)%MOD;
            oddcnt++;
        }
    }
    return cnt;
    }
};