class ParserError(Exception):
	pass

class Sentence(object):

	def __init__(self, subj, verb, obj):
		"""word_list contains string tuples of (type, word)"""
		self.subj = subj[1]
		self.verb = verb[1]
		self.obj = obj[1]

def peek(word_list):
	if word_list:
		word = word_list[0]
		return word[0]
	else:
		return None

def match(word_list, expecting):
	if word_list:
		word = word_list.pop(0)
		if word[0] == expecting:
			return word
		else:
			return None
	else:
		return None

def skip(word_list, word_type):
	while peek(word_list) == word_type:
		match(word_list, word_type)

def parse_verb(word_list):
	skip(word_list, "stop")

	print(peek(word_list))
	if peek(word_list) == "verb":
		return match(word_list, "verb")
	else:
		raise ParserError("Expected a verb.")

def parse_object(word_list):
	skip(word_list, "stop")
	next_word_type = peek(word_list)

	if next_word_type == "noun":
		return match(word_list, "noun")
	elif next_word_type == "direction":
		return match(word_list, "direction")
	else:
		return ParserError("Expected an object")

def parse_subject(word_list):
	skip(word_list, "stop")
	next_word_type = peek(word_list)

	if next_word_type == "noun":
		return match(word_list, "noun")
	elif next_word_type == "verb":
		return ("noun", "player")
	else:
		return ParserError("Expected a subject")

def parse_sentence(word_list):
	subj = parse_subject(word_list)
	verb = parse_verb(word_list)
	obj = parse_object(word_list)

	return Sentence(subj, verb, obj)
		
