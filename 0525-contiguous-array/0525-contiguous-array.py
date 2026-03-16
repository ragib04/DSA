class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        
        mp = {}
        cnt = 0
        maxLen = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                cnt -= 1
            else:
                cnt += 1

            if cnt == 0:
                maxLen = i + 1

            if cnt not in mp:
                mp[cnt] = i
            else:
                maxLen = max(maxLen, i - mp[cnt])

        return maxLen