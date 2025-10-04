class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
     
        int Area = 0;
        while(i<j){
            int h = min(height[i], height[j]);
            int w= j-i;
            Area = max(Area, h*w);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return Area;
    }
};