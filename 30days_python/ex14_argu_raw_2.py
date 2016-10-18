from sys import argv

script, user_name = argv

prompt = '>'

print "Hi %s, I'm the %s script." %(user_name, script)
print "I'd like to ask you a few questions."

print "Do you like me %s?" %user_name
likes = raw_input(prompt)

print "Where do you live %s?" %user_name
lives = raw_input(prompt)

print "What kind of computer do you have?"
computer = raw_input(prompt)

print "say do you love me, %s ?" %user_name
loves = raw_input(prompt)

print "say i love you."
says = raw_input(prompt)

print """

Alright, so you said %r about liking me.
You live in %r. Not sure where that is.
And you have a %r computer. Nice.
So, you said %r about loving me.
And ,you said %r.
""" %(likes,lives,computer,loves,says)
