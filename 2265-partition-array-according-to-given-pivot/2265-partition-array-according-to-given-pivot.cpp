class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> list1, list2;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<pivot) list1.push_back(nums[i]);
            else if(nums[i]>pivot) list2.push_back(nums[i]);
        }

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == pivot) list1.push_back(nums[i]);
        }
        // for(int i = 0 ; i<list2.size(); i++){
        //     list1.push_back(list2[i]);
        // }
        list1.insert(list1.end(), list2.begin(), list2.end());
        nums = list1;
        return nums;
    }
};