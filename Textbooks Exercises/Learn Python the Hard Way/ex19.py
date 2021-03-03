def cheese_and_crackers(cheese_count, boxes_of_crackers):
	print(f"{boxes_of_crackers} boxes of crackers.")
	print(f"{cheese_count} slices of cheese.")
	cheese_count = 10
	boxes_of_crackers = 10

def c_n_c(cc, boc, num):
	print(f"BOC = {boc}")
	print(f"CC = {cc}")
	return cc+boc+num

cheese_and_crackers(1, 1)

ch = 5
cr = 5

cheese_and_crackers(ch, cr)

print(f"This much cheese: {ch}; and this many crackers: {cr}")

cheese_and_crackers(c_n_c(ch,cr,1), c_n_c(ch,cr,2))
