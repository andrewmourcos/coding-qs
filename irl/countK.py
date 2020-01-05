"""
Given a sorted list L and an integer K, count the number of K's in the list.

ex:
	input: L = [2,3,3,3,3,5,6,6,9], K=3
	return: 4
	reason: there are 4 "threes" in the list
"""

def getLeftBound(L, k):
	mid = int( len(L)/2 )

	if (L[mid] > k):
		getLeftBound(L[mid:], k)
	elif (L[mid] < k):
		getLeftBound(L[:mid], k)
	else:
		return mid
