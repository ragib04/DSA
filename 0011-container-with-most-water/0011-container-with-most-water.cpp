class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

// // Brute force ----> O(n^2)
//          int area = 0;
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 int h = min(height[i], height[j]);
//                 int w = j-i;
//                 area = max(area, h*w);
//             }
//         }
//         return area;

//TWO POINTER ->>>>> O(N)
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