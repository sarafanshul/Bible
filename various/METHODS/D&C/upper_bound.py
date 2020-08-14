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

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}