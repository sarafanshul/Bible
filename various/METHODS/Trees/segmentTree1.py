# creating an array based segment TREE
# construction = O(N)
# space = O(N)
# searching =O(log(N))

# 1) pre-initialize segTree array with MAXX
MAX = 100000 # mostly high constraint

from math import ceil , log2 , pow

inpArr = [-1, 2, 4, 1]
N = 4  # any number
# length of seg tree = (pow of 2) - 1
height = ceil(log2(N))
# N = 2*(pow(2 , ceil(log2(N)))) - 1
N = int(2*(pow(2 , height)) - 1)
# N is approx ~ N = (4*N)

tree = [MAX for i in range(N)]

def constructTree(inpArr ,tree ,low ,high ,pos):
    # print(tree)
    if low == high:
        tree[pos] = inpArr[low]
        return
    
    mid = (low+high)//2
    constructTree(inpArr , tree , low , mid , 2*pos+1)
    constructTree(inpArr , tree , mid+1 , high ,2*pos+2)
    tree[pos] = min(tree[2*pos+1] , tree[2*pos+2])


def rangeMinQuery(tree , qlow , qhigh , low , high , pos):
    if (qlow <= low) and (qhigh >= high): #total overlap
        return tree[pos]
    if (qlow > high) or (qhigh < low): # no overlap returns MAX value
        return 1000000
    
    mid = (low + high)//2
    return min(rangeMinQuery(tree , qlow , qhigh , low , mid , 2*pos+1),
    rangeMinQuery(tree , qlow , qhigh , mid+1 , high , 2*pos+2))

low = pos = 0
high = len(inpArr)-1 
constructTree(inpArr, tree, low, high, pos)
# print(*tree)
print(rangeMinQuery(tree , 1 , 3 , low , high , pos))

