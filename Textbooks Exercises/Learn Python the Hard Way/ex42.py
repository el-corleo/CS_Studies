class Animal(object):

    def __init__(self, name):
        self.name = name

    def speak(self):
        print("Biscuit")

class Dog(Animal):

    def __init__(self, name):
        super(Dog, self).__init__(name)

    def speak(self):
        print("No biscuit")

class Cat(Animal):

    def __init__(self, name):
        super(Cat, self).__init__(name)
        self.name = "Bobo"


fido = Dog("Fido")
print(fido.name)
fido.speak()

miffy = Cat("Miffy")
print(miffy.name)
miffy.speak()

