m = 0
numbers = []

n = int(raw_input("please input n: "))
t = int(raw_input("please input t:"))

for i in range(n):
	print "At the top m is %d" % m
	numbers.append(m)
	m = m + t
	print "numbers now:", numbers
	print "At the bottom m is %d" % m

print "The numbers:" 
for num in numbers:
	print num