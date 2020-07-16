# ------------------------ Prefix SUM ------------------------

'''

'''

# 1) codechef KS1

def prefixXor(arr):
    output = [0]
    temp = 0
    out = dict()
    out[0] = [1 , 0]
    ans = 0

    for item in range(len(arr)):
        temp ^= arr[item]
        # creating a Prefix array
        output.append(temp)

        # creating base values with help of prefix array
        '''these base values are keys to a dictionary 
           eg {0:[1,0],etc} these base values hold two 
           values to a list 
           1) count = number of breakpoints 
                      to for subarray of ,
           2) sum  = sum of number of elements 
                     in these subarray(s) '''
        if not output[item+1] in out.keys():
            out[output[item+1]] = [0 , 0]


        count = out[output[item+1]][0]
        su = out[output[item+1]][1]

        # print(count,(item+1) , count , su)
        ''' here with the help of this formula
            {ans += count*item - count -sum}
            we find the total number of subarrays
            i.e answer '''
        ans += (count*(item+1)) - count - su
        count += 1

        # here we update the values
        out[output[item+1]][0] = count
        out[output[item+1]][1] += item+1
        # print(out)

    return ans

# driver Function
for _ in range(int(input())):
    N = int(input())
    arr = list(map(int , input().split()))
    print(prefixXor(arr))

# ==============================================================