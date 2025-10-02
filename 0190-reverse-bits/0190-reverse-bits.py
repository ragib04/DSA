class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        for i in range(32):
            result = (result << 1) | (n & 1)
            n >>= 1

        return result
        