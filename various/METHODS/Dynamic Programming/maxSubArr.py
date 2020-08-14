# Kadane's Algorithm to Maximum Sum Subarray 
# ------------in O(n) linear time-----------
# href : https://www.youtube.com/watch?v=86CQq3pKSUw


# algorithm 

# Kadane's Algoritnm Implementation
def maxArr(arr):
	max_current = max_global = arr[0]
	for i in range(1 , len(arr)):
		max_current = max(arr[i] , max_current + arr[i])
		if max_current > max_global:
			max_global = max_current
		else:
			max_current = 0
		return max_global


# drivers Function
if __name__ == '__main__':
	# arr = [1 , 2, 3, 4, -1 , 2, -4, -3, 100, 100, -1, 1]
	arr = list(map(lambda x : -x*2 ,range(2,20)))
	# arr = [-2 , 3, 2 , -1]
	maxArray = maxArr(arr)



# ============================================================== 
# def maxArr(arr):
# 	max_current = max_global = arr[0]
# 	for i in range(1 , len(arr)):
# 		max_current = max(arr[i] , max_current + arr[i])
# 		if max_current > max_global:
# 			max_global = max_current
# 		else:
# 			max_current = 0
# 		# print(i , max_current , max_global)
# 	# print(max_global)
# 	return max_global

# # arr = [1 , 2, 3, 4, -1 , 2, -4, -3, 100, 100, -1, 1]
# arr = list(map(lambda x : -x*2 ,range(2,20)))
# # arr = [-2 , 3, 2 , -1]
# print(arr)
# maxArr(arr)
