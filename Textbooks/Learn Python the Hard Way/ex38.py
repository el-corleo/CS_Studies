ten_things = "Apples Oranges Crows Telephone Light Sugar"

stuff = ten_things.split(' ')
more_stuff = ["Day", "Night", "Song", "Frisbee", "Corn"]

print(stuff)

while len(stuff) != 10:
	next_one = more_stuff.pop()
	stuff.append(next_one)

print(stuff)

# puts all items in list into a space-separated string
print(' '.join(stuff))
print('#'.join(stuff[3:5]))
