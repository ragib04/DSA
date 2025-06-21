class Solution {
public:

//intitution: sort unique first and return len ;all unique ele is starting of the arr

    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int j = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[j]){
                j++;    //move the unique to the next pos
                nums[j] = nums[i];
            }
        }
        return ++j; //return unique ele size which is j+1;
    }
};