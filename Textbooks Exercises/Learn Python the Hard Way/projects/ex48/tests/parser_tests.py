from nose.tools import *
from game.parser import *

def test_sentence():
	s = Sentence(("noun", "player"), ("verb", "run"), ("direction", "north"))
	assert_equal(s.subj, "player")
	assert_equal(s.verb, "run")
	assert_equal(s.obj, "north")

	s = parse_sentence([("noun", "bear"), ("verb", "eat"), ("stop", "the"), ("noun", "honey")])
	assert_equal(s.subj, "bear")
	assert_equal(s.verb, "eat")
	assert_equal(s.obj, "honey")
