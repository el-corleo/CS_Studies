from sys import argv

script, filename = argv

print(f"We're going to erase {filename}")
print("If you don't want to, hit ctrl-c")
print("If you do, hit ENTER")

input("Well..?")

print("Opening the file...")
target = open(filename, "w")

print("Truncating...")
target.truncate()

print("Now write three lines:")
line1 = input("Line 1:")
line2 = input("Line 2:")
line3 = input("Line 3:")

target.write(line1 + "\n" + line2 + "\n" + line3)

print("Now we close it")
target.close()
