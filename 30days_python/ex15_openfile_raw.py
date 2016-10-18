# from sys import argv
# read filename
# script, filename = argv
# open

filename = raw_input("please input your filename:")

txt = open(filename)
# read & print
print "Here's your file %r:" %filename
print txt.read()


print "Type the filename again:"

file_again = raw_input("> ")
txt_again = open(file_again)

print txt_again.read()
