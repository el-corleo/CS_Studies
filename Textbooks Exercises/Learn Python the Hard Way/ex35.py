from sys import exit

def meth(quit):
	if quit == 'Y':
		exit(0)

while(True):
	print("Exit?")
	meth(input("> "))

