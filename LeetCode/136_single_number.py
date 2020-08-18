# We're given a list of numbers that come in pairs. Find the one number without a pair

# Attempt 1 -- O(n^2), extra memory
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        
        loners = []
        for elem in nums:
            if elem not in loners:
                loners.append(elem)
            else:
                loners.remove(elem)
                
        return loners[0]
            
# Attempt 2 -- hashmap O(n), extra memory
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_nums = defaultdict(int)
        
        for elem in nums:
            hash_nums[elem] += 1
            
        for elem in hash_nums:
            if hash_nums[elem] == 1:
                return elem

# Attempt 3 -- XOR, O(n), no extra memory
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        loner = 0
        for elem in nums:
            loner ^= elem
        return loner