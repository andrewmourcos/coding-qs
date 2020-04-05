
# def scheduler(range_list):
# 	range_list = sorted(range_list key=lambda r: r.start)
# 	for 

# def main():
# 	num_tests = int(input())
# 	for test in range(num_tests):
# 		num_activities = int(input())

# 		range_list = []
# 		for activity in range(num_activities):
# 			start_time, end_time = (int(i) for i in input().split(" "))
# 			range_list.append(range(start_time, end_time))

# 		return 


def main():
	num_tests = int(input())
	for test in range(num_tests):
		num_activities = int(input())

		parentA = [None]*1441
		parentB = [None]*1441
		out_string = ''
		for activity in range(num_activities):
			start_time, end_time = (int(i) for i in input().split(" "))
			if out_string == "IMPOSSIBLE":
				continue

			if all(v is None for v in parentA[start_time+1:end_time]):
				out_string+='C'
				# print('C')
				parentA = [1 if x <= end_time and x >= start_time else v for x, v in enumerate(parentA)]

			elif all(v is None for v in parentB[start_time+1:end_time]):
				out_string+='J'
				# print('J')
				parentB = [1 if x <= end_time and x >= start_time else v for x, v in enumerate(parentB)]
			else:
				out_string="IMPOSSIBLE"
				# print("IMPOSSIBLE")
			# import IPython
			# IPython.embed()

		print("Case #{}: {}".format(test+1,out_string))


if __name__ == '__main__':
	main()





