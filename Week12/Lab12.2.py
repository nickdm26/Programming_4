import random

def removeTheVowelsImp(inputString):
    vowels = ["a", "i", "e", "o", "u"]
    theConsonants = "".join([x for x in inputString if x not in vowels])
    return theConsonants

test = removeTheVowelsImp("This is a Test String")
print(test)

print(" ")

vowels = ["a", "i", "e", "o", "u"]
weekDays = ["Monday", "Tuesday", "Wednesday", "Thursday", "Firday"]
noVowels = ["".join([x for x in d if x not in vowels])  for d in weekDays]
print(noVowels)

print(" ")

numbers = [11, -17, 42, 8, -12, 9]
onlypostive = [x if x > 0 else 0 for x in numbers]
print(onlypostive)

print(" ")

class FlashCards:
    def __init__(self, InputList):
        self.wordList = InputList

    def __iter__(self):
        return self

    def __next__(self):
        wordNum = len(self.wordList) - 1
        ranWord = random.randint(0, wordNum)
        currentWord = self.wordList[ranWord]
        return currentWord

germanWords = FlashCards(["die kuh", "der hund", "die katze", "das Pferd", "die Ente"])
for i in range(5):
    print(next(germanWords))


print(" ")

def listReverser(inputStringList):
    inputStringList.reverse()
    for x in inputStringList:
        yield x

g = listReverser(["antelope", "burro", "cheetah", "donkey", "elephant"])

for w in g:
    print(w)

print(" ")

qt = listReverser(["antelope", "burro", "cheetah", "donkey", "elephant"])
sevenOrMore = [w for w in qt if len(w) >= 7]
print(sevenOrMore)