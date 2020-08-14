# # ---------TOO SLOW--------

# Initialize the matrix with 0 
# mx = 998

# l = [[0 for i in range(mx)] for j in range(mx)] 
  
# def initialize(): 
	  
# 	# 0C0 = 1 
# 	l[0][0] = 1
# 	for i in range(1, mx): 
		  
# 		# Set every nCr = 1 where r = 0 
# 		l[i][0] = 1
# 		for j in range(1, i + 1): 
			  
# 			# Value for the current cell of Pascal's triangle 
# 			l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]) 
  
# # Function to return the value of nCr 
# def nCr(n, r):  
# 	# Return nCr 
# 	return l[n][r] 
  
# # Driver code 
# # Build the Pascal's triangle 
# from time import time
# s = time()
# initialize()
# print(time() - s) 
# n = 8
# r = 3
# print(nCr(n, r)) 