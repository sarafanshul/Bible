#      -- DIGIT-DP --
# more like a sequence dynamic programming
# k = predefined
# condition parameter 
	# sum = 0 - sum
# edge = bool (if on edge or not)

 
# using - https://www.spoj.com/problems/RAONE/

def main() -> None:

	def raOneNums(number) -> 'countNumbersWithDiff':
		# 162 because sum can be max 81*2 
		dp = [[[-1 for i in range(2)]for j in range(162)]for k in range(9)]

		def countNumbersWithDiff(number, idx, difference, onEdge) -> int:
		
			count = 0
			sign = 1

			if not (len(number) - 1 - idx)%2 : sign = -1 # for even odd differences

			if dp[idx][difference + 81][0 if onEdge else 1] != -1 :
				return dp[idx][difference + 81][0 if onEdge else 1]

			elif idx == len(number) - 1:
				if difference >= -8 and difference <= 10 :
					# 1-9 and 1+9
					if onEdge:
						currentDigit = int(number[idx]) 
						if sign == 1 and difference <= 1 and difference + currentDigit >= 1 :
							count = 1
						elif sign == -1 and difference >= 1 and difference - currentDigit <= 1 :
							count = 1
					else:
						if sign == 1 :
							count = 1 if difference <= 1 else 0
						else:
							count = 1 if difference >= 1 else 0

			elif onEdge:
				currentDigit = int(number[idx])
				for i in range(currentDigit): count += countNumbersWithDiff( number, idx+1, difference+i*sign, False)
				
				count += countNumbersWithDiff( number, idx+1, difference+currentDigit*sign, True)

			else:
				for i in range(10): count += countNumbersWithDiff( number, idx+1, difference+i*sign, False)

			dp[idx][difference + 81][0 if onEdge else 1] = count

			return count				

		return countNumbersWithDiff(number, 0, 0, True)


	for _ in range(int(input())):
		L , R = input().split()
		print(raOneNums(R) - raOneNums(str(int(L)-1)))
	
	return

if __name__ == '__main__':
	main()