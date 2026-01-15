class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(), vBars.end());
        int hmax=1;
        int vmax = 1;
        int len = 1;
        int n1 = hBars.size();
        int m1 = vBars.size();
        for(int i=1;i<n1;i++){
            if(hBars[i]-hBars[i-1]==1) len++;
            else len = 1;
            hmax = max(len,hmax);
        }
        len = 1;
        for(int i=1;i<m1;i++){
            if(vBars[i]-vBars[i-1]==1) len++;
            else len = 1;
            vmax = max(len,vmax);
        }
        return (min(hmax,vmax) + 1) * (min(hmax,vmax) + 1);
    }
};