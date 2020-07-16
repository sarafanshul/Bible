# https://codeforces.com/problemset/problem/489/C

def check (s , m):

	if m==1 and s==0:
		return (0,0)
		
	elif s > m*9 or s == 0:
		return (-1,-1)

	else:
		
		Low = 10**(m-1)		
		for i in range(s-1):
			Low += 10**(i//9)

		High = 0
		for i in range(s):
			High += 10**(m-1-i//9)

		return (Low , High)


m , s = map(int , input().split())

print(*check(s , m)) 
