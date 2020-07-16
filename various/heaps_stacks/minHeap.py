# ----------Min Heap---------
# public functions = push , peek , pop
# private functions = __swap , __floatUp , __bubbleDown

class MinHeap(object):
  	"""docstring for MinHeap"""
  	def __init__(self, items = []):
  		super().__init__()
  		self.heap = [0]
  		for i in items:
  			self.heap.append(i)
  			self.__floatUp(len(self.heap) - 1)

  	def push(self , data):
  		self.heap.append(data)
  		self.__floatUp(len(self.heap) - 1)

  	def peek(self):
  		if self.heap[1]:
  			return self.heap[1]
  		return False
  	
  	def pop(self):
  		if len(self.heap) > 2:
  			self.__swap(1 , len(self.heap) - 1)
  			max = self.heap.pop()
  			self.__bubbleDown(1)
  		elif len(self.heap) == 2:
  			max = self.heap.pop()
  		else:
  			max = False
  		return max

  	def __swap(self , i , j):
  		self.heap[i] , self.heap[j] = self.heap[j] , self.heap[i]

  	def __floatUp(self , index):
  		parent = index//2
  		if index <= 1:
  			return
  		elif self.heap[index] < self.heap[parent]:
  			self.__swap(index , parent)
  			self.__floatUp(parent)

  	def __bubbleDown(self , index):
  		left = index * 2
  		right = (index * 2) - 1
  		smallest = index
  		if len(self.heap) > left and  self.heap[smallest] > self.heap[left]:
  			smallest = left
  		if len(self.heap) > right and  self.heap[smallest] > self.heap[right]:
  			smallest = right
  		if smallest != index:
  			self.__swap(index , smallest)
  			self.__bubbleDown(smallest)
  	def heapInfo(self):
  		print(f'heap = {self.heap[1:]} , len = {len(self.heap)-1}')

if __name__ == '__main__':
	m = MinHeap([9,8,7,6,5,4,2,1,0])
	m.heapInfo()