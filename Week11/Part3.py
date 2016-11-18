dogcount = 0
class Dog:

    species = 'Canis familiaris'
    dogCount = 0


    def __init__(self, name, breed):
        self.name = name
        self.breed = breed
        dogcount = dogcount + 1

    def bark(self):
        print("Woof")

    def describe(self):
        print("My name is " + self.name + ". I am a " + self.breed)

