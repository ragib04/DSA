class Solution(object):
    def maxDistinctElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        nums.sort()
        ans, prev = 0, -10**9
        for i in nums:
            left_ele = max(i-k, prev+1)
            if(left_ele <= i+k):
                prev = left_ele
                ans += 1
        return ans        
        