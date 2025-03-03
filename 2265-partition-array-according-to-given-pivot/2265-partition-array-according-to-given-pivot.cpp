class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // vector<int> list1, list2, list3;
        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i]<pivot) list1.push_back(nums[i]);
        //     else if(nums[i]>pivot) list2.push_back(nums[i]);
        //     else list3.push_back(nums[i]);
        // }

        // // for(int i = 0; i<nums.size(); i++){
        // //     if(nums[i] == pivot) list1.push_back(nums[i]);
        // // }
        // list1.insert(list1.end(), list3.begin(), list3.end());
        // // for(int i = 0 ; i<list2.size(); i++){
        // //     list1.push_back(list2[i]);
        // // }
        // list1.insert(list1.end(), list2.begin(), list2.end());
        // nums = list1;
        // return nums;


        //app2->>>>>>>>>
        int cntless = 0, cntequal = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<pivot){
                cntless++;
                } 
            else if(nums[i] == pivot) {
                cntequal++;
            }
        }
        vector<int> ans(nums.size());
        int i = 0, j= cntless, k = cntless+cntequal;

        for(int &num : nums){
            if(num<pivot){
                ans[i] = num;
                i++;
            }
            else if(num == pivot){
                ans[j] = num;
                j++;
            }
            else{
                ans[k] = num;
                k++;
            }
        }
        return nums = ans;
    }
};