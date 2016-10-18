from sys import argv
script, input_file = argv

def print_all(f):
	print f.read()

def rewind(f):
	f.seek(0)

def print_a_line(line_count, f):
	print line_count, f.readline()


current_file = open(input_file, 'w')
current_file.truncate()

print "Please say something: "
say1 = raw_input()
say2 = raw_input()
say3 = raw_input()
say = say1 + "\n" + say2 + "\n" + say2 + "\n" + say3 + "\n" + say3
current_file.write(say)
current_file.close()

current_file = open(input_file)
 
print "First let's print the whole file:\n"
print_all(current_file)

# maybe seek is relative to "readline"
print "Now let's rewind, kind of like a tape."
rewind(current_file)

print "Let's print three lines:"

current_line = 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)
