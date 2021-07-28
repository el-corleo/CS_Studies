from sys import argv
from os.path import exists

script, from_file, to_file = argv

print(f"Copying from {from_file} to {to_file}")

in_data = open(from_file).read()

print(f"The input file is {len(in_data)} bytes long")
print(f"Output file exists = {exists(to_file)}")

out_file = open(to_file, 'w').write(in_data)
