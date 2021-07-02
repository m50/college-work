ARTICLES = ("a", "an", "the")
INDEFINITE_PRONOUNS = ("another", "both", "everything", "nothing")
DEMONSTRATIVE_PRONOUNS = ("this", "that", "these", "those")
SUBJECTIVE_PERSONAL_PRONOUNS = ("I", "you", "he", "she", "it", "we", "they")

def decidePartOfSpeech(  ):
	'''defines part of speech'''
	word = raw_input( "Enter a word: " )
	if word in ARTICLES:
		print '"' + word + '" is an article.'
	elif word in INDEFINITE_PRONOUNS:
		print '"' + word + '" is an indefinite pronoun.'
	elif word in DEMONSTRATIVE_PRONOUNS:
		print '"' + word + '" is an demonstrative pronoun.'
	elif word in SUBJECTIVE_PERSONAL_PRONOUNS:
		print '"' + word + '" is an subjective personal pronoun.'
	else:
		print '"' + word + '" is not a part of speech we care about.'
		
