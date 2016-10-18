class lexicon(object):

	def __init__(self):
		self.whole_char = {'north':'direction', 'south':'direction', 'east':'direction', 'west':'direction', 
						   'down':'direction', 'up':'direction', 'left':'direction', 'right':'direction', 'back':'direction',
						   'stop':'verb', 'kill':'verb', 'eat':'verb', 'go':'verb',
						   'the':'stop', 'in':'stop', 'of':'stop', 'from':'stop', 'at':'stop', 'it':'stop',
						   'door':'noun', 'bear':'noun', 'cabinet':'noun', 'princess':'noun'
		}

	def scan(self, stuff):
		words = stuff.split()
		my_result = []
		for n in range(0,len(words)):
			c = words[n]
			a = self.charac(c)
			my_result.append(a)
		return my_result

	def charac(self, c):
		if c in self.whole_char:
			b = self.whole_char[c]
			return b, c
		else:
			return self.int_test(c)

	def int_test(self, c):
		try:
			c = int(c)
			return ('number', c)
		except:
			return ('error', c)

lexicon = lexicon()
#print lexicon.scan('open the door and smack the bear in the 32 nose')
