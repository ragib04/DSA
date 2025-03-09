class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), ans = 0, Wlen = 1;
        for(int i =1; i<=n-1+k-1; i++){
            if(colors[i%n] != colors[(i-1+n)%n]) {
                Wlen++;
                }
            else {
                Wlen = 1;
            }

            if(Wlen>=k) ans++;
        }

        return ans;
    }
};