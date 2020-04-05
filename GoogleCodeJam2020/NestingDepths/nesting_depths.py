"""
input: 312
(3)(1)(2)
(312) --> ( 201 )
          ( (2)0(1) ) --> ( ( 1 ) 0 (0) )
                          ( ((1)) 0 (0) ) --> ( ((0)) 0 (0) )
                          
output : ( ((3)) 1 (2) )

Idea 1:
    1) iterate through numbers and place parentheses if non-zero
    2) iterate again -- if ) touches (, delete them
    3) subtract 1 from all integers and recur
================================================================

input: 312

312	(312
^
312 (312
 ^
312	(312)
  ^
201 ( (312 )
^
201 ( (3)12 )
 ^
201 ( (3)1(2) )
  ^
100 ( ((3) 1 (2) )
^
100 ( ((3)) 1 (2))
 ^
100 ( ((3)) 1 (2))
  ^

O(n^9)
================================================================
input : 312
312 - split by 0 w/ par on outside
(312) - subtract by one
(201) - split by 0
((2)0(1)) - subtract by one
((1)0(0)) - split by 0
(((1)) 0 (0)) - subtract by one

(((0)) 0 (0)) - fill in old numbers

(((3)) 1 (2))
================================================================
"312"
["312"] --> ["201"]
			[["2"], "0", ["1"]]



"""
def splitAround(string, character):
	L = []
	chunk = ""
	for c in string:
		print(c)
		if c is not character: 
			chunk+=c
		else:
			L.append(chunk)
			L.append(character)
			chunk = ""
	L.append(chunk)
	return L

# def recursiveStringSplit(digit_string):
# 	split_string = digit_string.split("0")
# 	print(split_string)

# 	if not all(substring=='' for substring in split_string):
# 		for substring in split_string:
# 			subtracted = [int(s)-1 for s in list(substring)]
# 			recursiveStringSplit(''.join(map(str, subtracted)))


def nesting_depth(digit_string):
	character_list = []
	last_digit = 0
	for digit in digit_string:
		if (int(digit) - last_digit) >= 0:
			character_list.extend(['(' for _ in range(int(digit) - last_digit)])
		else:
			character_list.extend([')' for _ in range(last_digit-int(digit))])
		character_list.append(digit)
		last_digit = int(digit)

	if last_digit > 0:
		character_list.extend([')' for _ in range(last_digit)])

	return ''.join(map(str, character_list))

def main():
	num_tests = int(input())

	for test in range(num_tests):
		test_sample = str(input())
		parenthesized_output = nesting_depth(test_sample)
		print("Case #{}: {}".format(test+1, parenthesized_output))






if __name__ == '__main__':
	main()