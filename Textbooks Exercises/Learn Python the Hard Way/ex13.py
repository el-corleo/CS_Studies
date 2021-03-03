from sys import argv

script = argv[0]
num = int(argv[1])
boolean = bool(argv[2])

user_input = input("Type something in: ")

print("The script is called:", script)
print("The first variable is:", num)
print("The second is:", boolean)
print("The third is:", user_input)
