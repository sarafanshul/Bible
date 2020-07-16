# in binary search we will return index of missing ellement (if there) of a sorted array

def check(short = True) -> list or int:
	def inner(fun):
		def warpper(*args):
			if args[1] < args[0][0]:
				if short : return [0]
				return f'element is min'
			elif args[1] > args[0][-1]:
				if short : return [-1]
				return f'element is max'
			a , b = fun(args[0] , args[1])
			if a == -1:
				if short: return b
				return f'found at index {b}'
			if short: return [a , b]
			return f'place between {args[0][a]} and {args[0][b]}'
		return warpper
	return inner

@check(1) # 1 == anly required values , 0 for printed statement
def binarySearch(arr , element):
	high , low = len(arr) - 1 , 0
	while True:
		mid = (high + low)//2
		if high < low : return (low , high)
		if arr[mid] == element: return (-1 , mid)
		if element < arr[mid]: high = mid - 1
		else : low = mid + 1

def main():
	*arr , = [1,2,3,4,6,7,7,8,9,12,23,45,56,64,67,78]
	print(binarySearch(arr , 63) ,binarySearch(arr , 163) ,\
		binarySearch(arr , 64) , binarySearch(arr , 0),\
		sep = '\n')

# if __name__ == '__main__':
# 	main()


# def upper_bound(arr_pir ,value):

# 	def binary_search(arr_pir ,value):
# 		if value > arr_pir[-1][0]:
# 			return len(arr_pir)

# 		low, high = 0, len(arr_pir)-1
# 		flag = 1
# 		# while low <= high:
# 		while low <= high:
# 			# print(low ,high)
# 			mid = low + (high - low) // 2
# 			mid_value = arr_pir[mid][0]
# 			# if value < mid_value:
# 			# 	return mid
# 			if mid_value == value and flag:
# 				# return mid
# 			# 	pass
# 				flag = 0
# 			elif mid_value < value:
# 				low = mid + 1
# 			else: # mid_value > value
# 				high = mid - 1
# 			# if flag and value > mid_value:
# 		return mid
# 	return binary_search(arr_pir ,value) + 1

# arr = [[1 ,0],[2 ,1],[3 ,2],[4 ,3],[5 ,4],[6 ,5],[7 ,6],[8 ,7],[9 ,8] ,[11,9]]
# print(upper_bound(arr ,0))

# def upper_bound(arr , x):
# 	l = 0
# 	h = len(arr)

# 	while l < h:
# 		mid = (l+h)//2
# 		if x >= arr[mid][0]:
# 			l = mid +1
# 		else:
# 			h = mid
# 	return l

# arr = [[1 ,0],[2 ,1],[3 ,2],[4 ,3],[5 ,4],[6 ,5],[7 ,6],[8 ,7],[9 ,8] ,[11,9]]
# print(upper_bound(arr ,11))

# int bs_upper_bound(int a[], int n, int x) {
#     int l = 0;
#     int h = n; // Not n - 1
#     while (l < h) {
#         int mid = (l + h) / 2;
#         if (x >= a[mid]) {
#             l = mid + 1;
#         } else {
#             h = mid;
#         }
#     }
#     return l;
# }

# int bs_lower_bound(int a[], int n, int x) {
#     int l = 0;
#     int h = n; // Not n - 1
#     while (l < h) {
#         int mid = (l + h) / 2;
#         if (x <= a[mid]) {
#             h = mid;
#         } else {
#             l = mid + 1;
#         }
#     }
#     return l;
# }