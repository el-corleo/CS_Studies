# Used to properly reformat:
#	- book files from old style to new
#	- video files to a standard format

import os

def books(filename):
	if "[" in filename:
		category = filename[filename.find("["):filename.find("]")+1]
		author = "[" + filename[filename.find("]")+2:filename.find("-")-1] + "]"
		title = "[" + filename[filename.find("-")+2:filename.find(".")] + "]"
		extension = filename[filename.find("."):]
		os.rename(filename, category+author+title+extension)
		#print(category+author+title+extension)

def videos(filename):
	if "invader" in filename:
		new_name = filename[filename.find("-")+2:]
		new_name = new_name[:new_name.find("(")-1]+".mkv"
		os.rename(filename, new_name)
		#print(new_name)

for filename in os.listdir():
	#books(filename)
	videos(filename)
	