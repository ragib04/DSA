class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return -1;
        int dist = INT_MAX;
        bool flag = false;
        for(int i = 0; i<n-2;i++){
            for(int j = i+1; j<n-1;j++){
                if(nums[j] == nums[i]){
                    for(int k = j+1; k<n; k++){
                        if(nums[k] == nums[j]){
                            flag = true;
                            int cur_dis = abs(i-j)+abs(j-k)+abs(k-i);
                            dist = min(cur_dis, dist);
                        }
                    }
                }
            }
        }
        if(flag == false) return -1;
        return dist;
    }
};