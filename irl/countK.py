"""
Given a sorted list L and an integer K, count the number of K's in the list.

ex:
	input: L = [2,3,3,3,3,5,6,6,9], K=3
	return: 4
	reason: there are 4 "threes" in the list
"""

def getLeftBound(L, k, mid_sum):
	if len(L) <= 1:
		print("not found")
		return 

	mid = len(L)//2 
	print(L, mid, mid_sum)

	if (L[mid] > k):
		# go left
		return getLeftBound(L[:mid], k, mid_sum+mid)
	elif (L[mid] < k):
		# go right
		return getLeftBound(L[mid:], k, mid_sum+mid)
	else:
		return mid


if __name__ == '__main__':
	L = [1,2,3,3,3,4,5,6,6,6,6,6,6,6,6,6]
	k = 5
	i = getLeftBound(L, k, 0)
	print(i)
