directions = ["north", "south", "east", "west"]
verbs = ["go", "kill", "eat"]
nouns = ["bear", "princess"]
stops = ["the", "of", "in"]
        
def scan(sentence):
    sentence = sentence.lower()
    word_categories = []
    words = sentence.split()
    for word in words:
        try:
            if word in directions:
                word_categories.append(("direction", word))
            elif word in verbs:
                word_categories.append(("verb", word))
            elif word in nouns:
                word_categories.append(("noun", word))
            elif word in stops:
                word_categories.append(("stop", word))
            else:
                word_categories.append(("number", int(word)))
        except:
            word_categories.append(("error", word))
    return word_categories



