class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n = len(nums)
        sum = 0
        for i in nums:
            sum += i
        if sum%2 == 0:
            return n-1
        else:
            return 0

