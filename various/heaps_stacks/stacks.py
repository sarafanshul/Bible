# # -------Stack Data Structure---------
'''
stack are just like lists but we can custamize it
'''
class Stack():
	
	def __init__(self):
		self.items = []

	def push(self , *item):
		# self.items.extend(item)
		self.items += item

	def pop(self):
		return self.items.pop()

	def peek(self):
		if not self.is_empty():
			return self.items[-1]

	def get_stack(self):
		return self.items

	def is_empty(self):
		return self.items == []


if __name__ == '__main__':
	s = Stack()
	# s.push('A')
	# s.push('B')
	# s.push('C')
	# s.push('D')
	# s.push('E')
	# s.push('F')
	s.push('a',1,2,3,4,56,7,8,8,1.0,'%$')
	print(s.get_stack())
	s.pop()
	print(s.get_stack())
	print(s.is_empty())
	print(s.peek())
