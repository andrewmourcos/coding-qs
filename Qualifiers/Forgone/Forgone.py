def checkSplit(N):
	digits = [int(x) for x in str(N)]
	A = []
	B = []
	print(digits)
	for i in range(len(digits)):
		if digits[i] is 4:
			B.append(digits[i]*10*(len(digits) - i))
		else:
			A.append((digits[i])*10*(len(digits) - i))

	for i in range(len(B)):
		if B[i] is 4:
			B[i] = B[i]/2

	B = sum(B)
	A = sum(A) + B
	print(A, B)

checkSplit(12348)