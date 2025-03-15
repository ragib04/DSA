class Solution {
public:
bool ispossible(int mid, vector<int> &nums, int k){
    int housecnt = 0;
    for(int i =0; i<nums.size(); i++){
        if(nums[i]<=mid){
            housecnt++;
            i++;
        }
    }
    return (housecnt >= k);
}
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int s = *min_element(begin(nums), end(nums));
        int e = *max_element(begin(nums), end(nums));
int res = e;
        while(s<=e){
            int mid = (s+e)/2;

            if(ispossible(mid, nums, k)){
                res = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return res;
    }
};