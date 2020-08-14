
------------------- DIFFERENCE ARRAY -------------------------

# aka Range and Update Query

'''
	Difference array D[i] of a given array A[i] 
	is defined as D[i] = A[i]-A[i-1] (for 0 < i < N ) 
	and D[0] = A[0] considering 0 based indexing. 
	Difference array can be used to perform range 
	update queries "l r x" where l is left index, 
	r is right index and x is value to be added 
	and after all queries you can return original 
	array from it. Where update range operations 
	can be performed in O(1) complexity.

1) update(l, r, x) : Add x to D[l] 
					and subtract it from D[r+1], 
					i.e., we do 
						D[l] += x, D[r+1] -= x

2) printArray() : Do A[0] = D[0] and print it. 
				For rest of the elements, do 
				A[i] = A[i-1] + D[i] 
				and print them.
	
	Time complexity of update here is improved to O(1). 
	Note that printArray() still takes O(n) time.
'''

===============================================================
# 1) geeks for geeks 

# Creates a diff array D[] for A[] and returns 
# it after filling initial values. 
def initializeDiffArray( A): 
    n = len(A) 
  
    # We use one extra space because 
    # update(l, r, x) updates D[r+1] 
    D = [0 for i in range(0 , n + 1)] 
  
    D[0] = A[0]; D[n] = 0
      
    for i in range(1, n ): 
        D[i] = A[i] - A[i - 1] 
    return D 
  
# Does range update 
def update(D, l, r, x): 
  
    D[l] += x 
    D[r + 1] -= x 
  
# Prints updated Array 
def printArray(A, D): 
  
    for i in range(0 , len(A)): 
        if (i == 0): 
            A[i] = D[i] 
  
        # Note that A[0] or D[0] decides 
        # values of rest of the elements. 
        else: 
            A[i] = D[i] + A[i - 1] 
  
        print(A[i], end = " ") 
      
    print ("") 
  
# Driver Code 
A = [ 10, 5, 20, 40 ] 
  
# Create and fill difference Array 
D = initializeDiffArray(A) 
  
# After below update(l, r, x), the 
# elements should become 20, 15, 20, 40 
update(D, 0, 1, 10) 
printArray(A, D) 
  
# After below updates, the 
# array should become 30, 35, 70, 60 
update(D, 1, 3, 20) 
update(D, 2, 2, 30) 
printArray(A, D) 

=============================================================

# 2) difference array for an hackerrank Question

N , k = map(int , input().split())
a = [0 for i in range(N+1)]

for i in range(k):
	p , q , su = map(int , input().split())
	a[p] += su
	if q+1 <= N :
	a[q+1] -= su
x = 0
maxx = 0
for i in range(1 , N+1):
	x += a[i]
	if maxx < x : maxx = x

print(maxx) 

======================================================

# 3) ZOMCAV
# solved using difference array 
# codechef ZOMCAV

def ZomRad(arr):
    for i in range(1 , len(arr)):
        arr[i] = arr[i] + arr[i-1]
    arr.pop()
    del arr[0]
    return arr
for _t in range(int(input())):
    n = int(input())
    c = list(map(int , input().split()))
    h = list(map(int , input().split()))
    # rLevel = [0 for i in range(n+2)]
    rLevel = [0]*(n+2)
    lm = len(rLevel)
    
    for i in range(0 , n):
        rLevel[max(1 , i+1-c[i])] += 1
        rLevel[min(i+1+c[i]+1 , n+1)] -= 1
    # print(rLevel)
    rLevel = ZomRad(rLevel)
    
    # print(rLevel)
    if sorted(h) == sorted(rLevel): print('YES')
    else: print('NO')


============================================================







# testfiles

# def UpdateArr(l , r , D):
# 	D[l] += 1
# 	D[r+1] -= 1

# def finalOut(A , D):
# 	for i in range(len(A)):
# 		if i==0:
# 			A[i] = D[i]
# 		else:
# 			A[i] = D[i] + A[i-1]


# for case in range(int(input())):
# 	N = int(input())
# 	*pov , = map(int , input().split())
# 	# pov = [1,2,3,4,5]
# 	D = [0 for i in range(N+2)]

# 	for j in range(len(pov)):
# 		if j - pov[j] >= 0 and j+pov[j] <  N:
# 			UpdateArr(j - pov[j] , j+pov[j] , D)

# 		elif j - pov[j] < 0 and j+pov[j] <= N:
# 			UpdateArr(0 , j+pov[j] , D)

# 		elif j - pov[j] >= 0 and j + pov[j] > N:
# 			UpdateArr(j-pov[j] , N-1 , D)

# 		elif j - pov[j] < 0 and j + pov[j] >= N:
# 			UpdateArr(0 , N-1 , D)
# 		# else :
# 		# 	UpdateArr(0 , N-1 , D)
# 		# print(D)
# 	power = [0 for i in range(N)]
# 	finalOut(power , D)
# 	final_power = sorted(power)
# 	# print(final_power)
# 	*H , = map(int , input().split())
# 	final_zom = sorted(H)
# 	if final_zom == final_power :
# 		print('YES')
# 	else:
# 		print('NO') 

# def UpdateArr(l , r , D):
# 	D[l] += 1
# 	D[r+1] -= 1

# def finalOut(A , D):
# 	for i in range(len(A)):
# 		if i==0:
# 			A[i] = D[i]
# 		else:
# 			A[i] = D[i] + A[i-1]


# for case in range(int(input())):
# 	# N = int(input())
# 	N = 5
# 	# *pov , = map(int , input().split())
# 	pov = [1,2,3,4,5]
# 	D = [0 for i in range(N+1)]

# 	for j in range(N):
# 		D[max([0 , j - pov[j]])] += 1
# 		D[min([N , j + pov[j]+1])] -= 1
# 		# print(D)	
# 	power = [0 for i in range(N)]
# 	finalOut(power , D)
# 	final_power = sorted(power)
# 	# print(final_power)
# 	*H , = map(int , input().split())
# 	final_zom = sorted(H)
# 	if final_zom == final_power :
# 		print('YES')
# 	else:
# 		print('NO') 



