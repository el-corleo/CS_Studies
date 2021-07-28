# Used to rapidly generate CPP/Java files for programming puzzles
# Use: python3 CPFileGenerator.py > CodeForces/900/Example.cpp

from sys import argv
from pathlib import Path

script, filename = argv

path = script[0:script.find('CPFile')]

# Open template file
content = ""
if '.cpp' in filename:
	filepath = Path(path + 'CPPtemplate.txt')
	content = open(filepath).read()
	print(content) # prints to standard input
else:
	filepath = Path(path + 'JavaTemplate.txt')
	content = open(filepath).read()
	print(content) # prints to standard input
