'''
class A(object):
	def __init__(self, arg):
		print "Inside class A init. arg =", arg

class B(A):
	def __init__(self):
		super(B, self).__init__("foo")
		print "Inside class B init"

b = B()
'''
# Inside class A init. arg = foo
# Inside class B init


class A(object):
	def __init__(self):
		print "Inside class A init"

class B(A):
	def __init__(self):
		super(B, self).__init__()
		print "Inside class B init"

b = B()

# Inside class A init
# Inside class B init