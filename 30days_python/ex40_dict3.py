cities = {'CA': 'San Francisco', 'Mi': 'Detroit', 'FL': 'Jacksonville'}
cities['NY'] = 'NewYork'
cities['OR'] = 'Portland'

def find_city(themap, state):
	if state in themap:
		return themap[state] #return cities['state input in while loop']
	else:
		return "Not found."

cities['_find'] = find_city
'''
print cities

{'CA': 'San Francisco', 'Mi': 'Detroit', 'NY': 'NewYork', 
'_find': <function find_city at 0x7ff961178398>, 
'FL': 'Jacksonville', 'OR': 'Portland'}
'''

while 1:
	print "State? (ENTER to quit)",
	state = raw_input("> ")
	if not state: break

	city_found = cities['_find'](cities, state)
	print city_found
