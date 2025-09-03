class Solution {
public:
static bool comp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        sort(points.begin(), points.end(), comp);
        for(int i = 0; i<n; i++){
            int y1 = points[i][1];
            int maxy = INT_MIN;
            for(int j = i+1; j<n; j++){
                int y2 = points[j][1];
                if(y2>y1) continue; //invalid point

                if(y2>maxy){
                    cnt++;
                    maxy = y2;
                }
            }
        }
        return cnt;
    }
};
