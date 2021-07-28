import os

for directory in os.listdir():
	if '.py' not in directory:
		for f in os.scandir(directory):
			print(directory+f)
