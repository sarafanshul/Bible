# # # memoization for the state results
# # dp = [[[-1 for i in range(2)] for j in range(180)] for k in range(20)]

# # def getDigits(num , lst):
# # 	while num:
# # 		lst.append( num%10 )
# # 		num //= 10

# # def digitSum(idx , sm , tight , digLst):

# # 	if idx == -1:
# # 		return sm

# # 	if (dp[idx][sm][tight] != -1) and (tight != 1):
# # 		return dp[idx][sm][tight]

# # 	if tight : k = digLst[idx]
# # 	else: k = 9

# # 	ret = 0
# # 	for i in range(k+1):
# # 		if digLst[idx] == i : newTight = tight
# # 		else: newTight = 0
# # 		ret += digitSum(idx-1 , sm+i , newTight , digLst)

# # 	if not tight:
# # 		dp[idx][sm][tight] = ret

# # 	return ret   


# # def rangeDigitSum(L , R):
# # 	digit_L = []
# # 	getDigits(L-1 , digit_L)
# # 	# print(digit_L)
# # 	ans1 = digitSum(len(digit_L)-1 , 0 , 1 , digit_L)

# # 	digit_R = []
# # 	getDigits(R , digit_R)
# # 	ans2 = digitSum(len(digit_R)-1 , 0 , 1 , digit_R)

# # 	return ans2 - ans1 


# # print(rangeDigitSum(123 , 1024))



# # # memoization for the state results
# # dp = [[[-1 for i in range(2)] for j in range(180)] for k in range(20)]

# # def getDigits(num , lst):
# # 	while num:
# # 		lst.append( num%10 )
# # 		num //= 10

# # def digitSum(idx , sm , tight , digLst):
# # 	print(f'idx={idx} sum={sm} tight={tight} , {digLst}')
# # 	if idx == -1:
# # 		return sm

# # 	if (dp[idx][sm][tight] != -1) and (tight != 1):
# # 		print('found')
# # 		return dp[idx][sm][tight]

# # 	if tight : k = digLst[idx]
# # 	else: k = 9

# # 	ret = 0
# # 	for i in range(k+1):
# # 		if digLst[idx] == i : newTight = tight
# # 		else: newTight = 0
# # 		ret += digitSum(idx-1 , sm+i , newTight , digLst)
# # 		print(ret)

# # 	if not tight:
# # 		dp[idx][sm][tight] = ret

# # 	print('return = ', ret)
# # 	return ret   


# # def rangeDigitSum(L , R):
# # 	digit_L = []
# # 	getDigits(L-1 , digit_L)
# # 	print('='*25)
# # 	print(digit_L)
# # 	ans1 = digitSum(len(digit_L)-1 , 0 , 1 , digit_L)

# # 	digit_R = []
# # 	getDigits(R , digit_R)
# # 	print('='*25)
# # 	print(digit_R)
# # 	ans2 = digitSum(len(digit_R)-1 , 0 , 1 , digit_R)

# # 	return ans2 - ans1 


# # print(rangeDigitSum(1 , 5))



# def solve(length , isequal):
# 	if length == 0 :
# 		# means that we have successfully build a number 
# 		# which is less than R

# 		''' ** This is the area where we will check if 
# 			 the number we have formed until now 
# 			 should be counted as one solution 
# 			 or not depending upon if 
# 			 it full fills our defined properties**'''
# 		return 1

# 	sol = 0
# 	if isequal == false:
# 		'''means that we have already fixed some digit x 
# 			which was less than digit of r at some previous length
# 			so now we can try all values because we 
# 			are sure that the number will be less than R
# 			always , for example R=4000 , if we fix 3 at 
# 			first position then it doesn't matter what 
# 			digit we fix now , the number 
# 			will be always less than R. '''
		
# 		for i in range(9+1):
# 			sol += solve(length-1 , 0)
	
# 	else:
# 		for i in range(R[length]+1):
# 			if i < R[length]:
# 				sol += solve(length-1 , 0)
# 			else:
# 				sol += solve(length-1 , 1)

# 	return sol	


# dp = [[[-1 for i in range(2)] for j in range(180)] for k in range(20)]

# def getDigits(num , lst):
# 	# while num:
# 	# 	lst.append( num%10 )
# 	# 	num //= 10
# 	*lst ,= map(int , str(num).split()) 

# def digitSum(idx , sm , tight , digLst):
# 	# print(f'idx={idx} sum={sm} tight={tight} , {digLst}')
# 	# break condition
# 	if idx == -1: return sm

# 	# memoization checking
# 	if (dp[idx][sm][tight] != -1) and (tight != 1): return dp[idx][sm][tight]

# 	k = 9
# 	if tight : k = digLst[idx]

# 	ret = 0
# 	for i in range(k+1):
# 		# if digLst[idx] == i : newTight = tight
# 		# else: newTight = 0
# 		# ret += digitSum(idx-1 , sm+i , newTight , digLst)
# 		ret += digitSum(idx-1 , sm+i , tight if digLst[idx] == i else 0 , digLst)

# 	# memoization updation
# 	if not tight: dp[idx][sm][tight] = ret

# 	return ret   

# # driver Function
# def rangeDigitSum(L , R):

# 	digit_L = []
# 	getDigits(L-1 , digit_L)
# 	ans1 = digitSum(len(digit_L)-1 , 0 , 1 , digit_L)

# 	digit_R = []
# 	getDigits(R , digit_R)
# 	ans2 = digitSum(len(digit_R)-1 , 0 , 1 , digit_R)

# 	return ans2 - ans1 


# print(rangeDigitSum(11 , 15))

MOD = int(1e7 + 7)

dp = [[[-1 for i in range(2)] for j in range(180)] for k in range(20)]

def getDigits(num):
	*lst ,= map(int , str(num).split())
	return lst

def digitSum(idx , sm , tight , digLst):
	# break condition
	if idx == -1: return sm

	# memoization checking
	if (dp[idx][sm][tight] != -1) and (tight != 1): return dp[idx][sm][tight]

	k = 9
	if tight : k = digLst[idx]

	ret = 0
	for i in range(k+1): ret += digitSum(idx-1 , sm+i , tight if digLst[idx] == i else 0 , digLst)

	# memoization updation
	if not tight: dp[idx][sm][tight] = ret

	return ret   

# driver Function
def rangeDigitSum(L , R) -> int:

	digit_L = getDigits(L-1)
	ans1 = digitSum(len(digit_L)-1 , 0 , 1 , digit_L)

	digit_R = getDigits(R)
	ans2 = digitSum(len(digit_R)-1 , 0 , 1 , digit_R)

	return (ans2 - ans1)%MOD

def main():
	print(rangeDigitSum(11 , 15000000))
	return

if __name__ == '__main__':
	main()

