import random

def odd_characters(input_word):
    returnstring = ""
    for i in range(1, len(input_word), 2):
        returnstring += input_word[i]

    return returnstring

def random_numbers():
    Min = 50
    Max = 50
    for i in range (0,10):
        tempnum = random.randint(0, 99)
        if(tempnum < Min):
            Min = tempnum
        elif(tempnum > Max):
            Max = tempnum
    print('Min: ' + str(Min))
    print('Max: ' + str(Max))

print(odd_characters("ThisIsATestString"))
random_numbers()