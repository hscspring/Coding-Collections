cities = {'CA': 'San Francisco', 'Mi': 'Detroit', 'FL': 'Jacksonville'}
cities['NY'] = 'NewYork'
cities['OR'] = 'Portland'

def find_city(themap, state):
	if state in themap:
		return themap[state]
	else:
		return "Not found."

#cities['_find'] = find_city

while True:
	print "State? (ENTER to quit)",
	state = raw_input("> ")
	if not state: break

	city_found = find_city(cities, state)
	print city_found
