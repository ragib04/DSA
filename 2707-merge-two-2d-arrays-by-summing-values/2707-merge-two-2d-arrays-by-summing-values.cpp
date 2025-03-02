class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int r1 = 0, r2 = 0;
        vector<vector<int>> ans; 
        while(r1<s1 && r2 < s2){
            if(nums1[r1][0] == nums2[r2][0]){
                ans.push_back({nums1[r1][0], nums1[r1][1]+nums2[r2][1]});
                r1++;r2++;
            }
            else if(nums1[r1][0] < nums2[r2][0]){
                ans.push_back({nums1[r1][0], nums1[r1][1]});
                r1++;
            }
            else{
                ans.push_back({nums2[r2][0], nums2[r2][1]});
                r2++;
            }
        }

        while(r1<s1){
            ans.push_back({nums1[r1][0], nums1[r1][1]});
            r1++;

        }
        while(r2<s2){
            ans.push_back({nums2[r2][0], nums2[r2][1]});
            r2++;
        }    

        return ans;    
    }
};