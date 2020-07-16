# /**
# * Date 04/27/2015
# * @author tusroy
# *
# * Write a program to implement fenwick or binary indexed tree
# *
# * A Fenwick tree or binary indexed tree is a data structure providing efficient methods
# * for calculation and manipulation of the prefix sums of a table of values.
# *
# * Space complexity for fenwick tree is O(n)
# * Time complexity to create fenwick tree is O(nlogn)
# * Time complexity to update value is O(logn)
# * Time complexity to get prefix sum is O(logn)
# *
# * References
# * http: // www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
# * https: // www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
# * http: // en.wikipedia.org/wiki/Fenwick_tree
# */

class fenwikTree:

    def __init__(self , N):
        self.binaryIndexTree = [0 for _ in range(N+1)]

    #  Start from index+1 if you updating index in 
    #  original array. Keep adding this value
    #  for next node till you reach outside range of tree

    def getnext(self , idx):
        # To get next:
        #   1) 2's complement of get minus of index
        #   2) AND this with index
        #   3) Add it to index
        return idx+(idx & -idx)
    
    def getParent(self , idx):
        # To get parent
        #   1) 2's complement to get minus of index
        #   2) AND this with index
        #   3) Subtract that from index
        return idx - (idx & -idx)
    
    def getsum(self , idx):
        idx += 1
        summ = 0
        while idx:
            summ += self.binaryIndexTree[idx]
            idx = self.getParent(idx)
        return summ

    def updateBinaryTree(self , val , idx):
        # Creating tree is like updating Fenwick tree for every value in array
        while(idx < len(self.binaryIndexTree)):
            self.binaryIndexTree[idx] += val
            idx = self.getnext(idx)
    
    def createTree(self , arr):
        for i in range(1 , len(arr)+1):
            self.updateBinaryTree(arr[i-1] , i)
        return self.binaryIndexTree
    
ar = [1,2,3,4,5,6,7]
ftree = fenwikTree(len(ar))
treearr = ftree.createTree(ar)
ftree.updateBinaryTree(10 , 1)
# print(treearr)

for i in range(0 , len(ar)):
    print(ftree.getsum(i))
