# python vestigium.py < input.txt > output.txt

def areRepeats(L):
	if len(set(L)) != len(L):
		return 1
	return 0

def main():
	number_of_matrices = int(input())
	for i in range(number_of_matrices):
		matrix_size = int(input())
		matrix_cols = [[] for _ in range(matrix_size)]
		trace, num_row_dup, num_col_dup = 0, 0, 0

		for j in range(matrix_size):
			jth_row = [int(s) for s in input().split(" ")]
			
			trace += jth_row[j]

			# Repeats on current row
			num_row_dup += areRepeats(jth_row)

			for n in range(matrix_size):
				matrix_cols[n].append(jth_row[n])

		num_col_dup = sum(areRepeats(col) for col in matrix_cols)

		print("Case #{}: {} {} {}".format(i+1, trace, num_row_dup, num_col_dup))


if __name__ == '__main__':
	main()