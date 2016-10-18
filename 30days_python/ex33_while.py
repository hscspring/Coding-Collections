i = 0
numbers = []

n = int(raw_input("please input n: "))
t = int(raw_input("please input t:"))

while i < n:
	print "At the top i is %d" % i
	numbers.append(i)
	i = i + t
	print "Numbers now: ", numbers
	print "At the bottom i is %d" % i

print "The nubers: "

for num in numbers:
	print num