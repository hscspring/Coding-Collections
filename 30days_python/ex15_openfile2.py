from sys import argv
# read filename
script, filename = argv
# open txt
txt = open(filename)
# read and print
print "Here's your file %r:" %filename
print txt.read()


# print "Type the filename again:"
# 
# file_again = raw_input("> ")
#
# txt_again = open(file_again)

# print txt_again.read()
