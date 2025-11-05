class Solution(object):
    def findXSum(self, nums, k, x):
        """
        :type nums: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        n = len(nums)
        res = []
        ctr = Counter()
        r = SortedList()
        l = SortedList()
        s = [0]  

        def balance():
            while len(r) > x:
                v = r.pop(0)
                s[0] -= v[0] * v[1]
                l.add(v)
            while len(r) < x and len(l) > 0:
                v = l.pop(-1)
                s[0] += v[0] * v[1]
                r.add(v)

        def add(val):
            if len(r) > 0 and val >= r[0]:
                s[0] += val[0] * val[1]
                r.add(val)
            else:
                l.add(val)
            balance()

        def remove(val):
            if len(r) > 0 and val >= r[0]:
                s[0] -= val[0] * val[1]
                r.remove(val)
            else:
                l.remove(val)
            balance()

        for i in range(n):
            if ctr[nums[i]]:
                remove((ctr[nums[i]], nums[i]))
            ctr[nums[i]] += 1
            add((ctr[nums[i]], nums[i]))
            if i >= k:
                remove((ctr[nums[i - k]], nums[i - k]))
                ctr[nums[i - k]] -= 1
                if ctr[nums[i - k]]:
                    add((ctr[nums[i - k]], nums[i - k]))
            if i >= k - 1:
                res.append(s[0])

        return res