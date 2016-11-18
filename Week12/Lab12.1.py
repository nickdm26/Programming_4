starWars = "A long time ago in a glaaxy far far away"
longWords = map(lambda x: x.upper(), filter(lambda x: len(x) >= 4, starWars.split()))
print(list(longWords))

def higherorderfunction(firstWorker, secondWorker, inputString):
    if (len(inputString) >= 4):
        result = firstWorker(inputString)
    else:
        result = secondWorker(inputString)
    return result

def secondUpper(inputString):
    returnString = map(lambda x: x.upper, inputString[0:-1:2])
    return returnString

def Lowercase(inputString):
    returnString = inputString.lower()
    return returnString

#output = higherorderfunction(Lowercase(), secondUpper(), "Test")
output = secondUpper("A long time ago in a glaaxy far far away")
print(output)