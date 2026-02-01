class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_mx[n];
        int right_mx[n];
        left_mx[0] = height[0];
        for(int i = 1; i<n; i++){
            left_mx[i] = max(left_mx[i-1], height[i]);

        }
        right_mx[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            right_mx[i] = max(right_mx[i+1], height[i]);
        }
        int trapwater = 0;
        for(int i =0; i<n; i++){
            trapwater += min(left_mx[i], right_mx[i]) - height[i];
        }
        return trapwater;
    }
};