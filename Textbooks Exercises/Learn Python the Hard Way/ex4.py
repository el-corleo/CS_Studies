cars = 100
space_in_car = 4.0
drivers = 30
passengers = 90
cars_not_driven = cars - drivers
cars_driven = drivers
carpool_cap = cars_driven * space_in_car
avg_pass_per_car = passengers / cars_driven

print("There are", cars, "cars available.")
print("There are only", drivers, "drivers available.")
print("There will be", cars_not_driven, "empty cars today.")
print("We can transport", carpool_cap, "people today.")
print("We have", passengers, "to carpool today.")
print("We need to put about", avg_pass_per_car, "in each car.")
