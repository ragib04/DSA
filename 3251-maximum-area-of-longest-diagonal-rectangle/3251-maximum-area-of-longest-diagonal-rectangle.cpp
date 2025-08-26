class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        float maxDiagonal = 0;
       
        for(int i = 0; i<dimensions.size(); i++){
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            
            float diagonal = sqrt((l*l)+(b*b));
            if(diagonal == maxDiagonal){
                maxArea = max(maxArea, l*b);
            }
            else if(diagonal>maxDiagonal){
                maxDiagonal = diagonal;
                maxArea = l*b;
            }
        }
        return maxArea;
    }
};