from sys import argv
# read filename
script, filename = argv
# open 
txt = open(filename)
# read & print
print "Here's your file %r:" %filename
print txt.read()
txt.close()

print "Type the filename again:"

file_again = raw_input("> ")

txt_again = open(file_again)

print txt_again.read()
txt_again.close()
