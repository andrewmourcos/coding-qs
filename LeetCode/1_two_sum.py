""" February 2019
runtime: 36ms [99th percentile]
memory: 7.9Mb [great!]
"""


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_table = dict()
        for ind, elem in enumerate(nums):
            result = target-nums[ind]
            if result in hash_table:
                return [hash_table[result], ind]
            hash_table[elem]=ind