# Triple quotes within the function act as documentation
# When you import this module into a python interpreter and
# call help(ex25) or help(ex.parse_words), it will print  
# function names and docs contained within the triple quotes

def parse_words(text, delimiter=' '):
	"""parses words splitting according to delimiter"""
	return text.split(delimiter)

def sort_words(text):
	"""sorts words (maj before min) in provided text"""
	return sorted(text)

def sort_sentence(sentence):
	"""sorts words (maj before min) in a given sentence"""
	return sort_words(parse_words(sentence))
