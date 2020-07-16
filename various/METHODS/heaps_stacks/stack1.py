# # -------Stack Data Structure---------
'''
stack are just like lists but we can custamize it
'''
# # balencing parentheses example

from stacks import Stack

def is_match(p1 , p2):
	if p1 == '(' and p2 == ')':
		return True
	if p1 == '[' and p2 == ']':
		return True
	if p1 == '{' and p2 == '}':
		return True

def is_balenced(par_str):
	s = Stack()
	is_balenced = True
	index = 0

	while (index < len(par_str)) and is_balenced:
		par = par_str[index]
		if par.isalnum() :pass
		elif par in '({[': s.push(par)
		else:
			if s.is_empty(): is_balenced = False
			else:
				top = s.pop()
				if not is_match(top , par):
					is_balenced = False
		index += 1
	if s.is_empty() and is_balenced:
		return True 

print(is_balenced('{smds}{sdj}()'))

	
