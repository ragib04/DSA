class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap(n+1);
        gap[0] = startTime[0];
        gap[n] = eventTime - endTime[n-1];
        for(int i = 1; i<n; i++){
            gap[i] = startTime[i] - endTime[i-1];
        }
        int i= 0, j= k;
        int maxi = 0, sum = 0;
        for(int w = i; w<=n && w<=j; w++){
            sum += gap[w];
        }
        maxi = max(maxi, sum);
        while(j<n){
            sum -= gap[i];
           i++;j++;
            sum += gap[j];

            maxi = max(maxi, sum);
        }
        return maxi;
    }
};