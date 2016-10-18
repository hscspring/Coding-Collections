class MyCode(object):

	def __init__(self, n):
		self.n = n

	def my_psd(self):

		if self.n == 8:
			return "19860927"
		elif self.n == 6:
			return "860927"
		elif self.n == 4:
			return "0927"
		else:
			print "You'are Wrong"