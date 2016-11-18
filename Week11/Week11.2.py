num_string = "0123456789"
print(num_string[4:8])
print(num_string[-6:-2])
print(num_string[5:])
print(num_string[1:8:2])
print(num_string[7:0:-2])

print()
print("Part 2")
print()
#2A
a = [1,2,3,4]
if 3 in a:
    print("2A: Yes 3 is in a")
elif 7 in a:
    print("2A: Yes 7")
#2B
if 99 not in a:
    print("2B: 99 is not in a")

if 3 not in a:
    print("2B: 3 is not in a")

#2C
estring = "Cat" + "Dog"
print("2C: " + estring)

#2D
dnum = 4 * 6
print("2D: " + str(dnum))

#2E
dog = "Im Am a Dog"
print("2E: " + str(len(dog)))

#2F
f = [1,2,3,4,5,6,7,8,9]
print("2F: Min: " + str(min(f)) + " Max: " + str(max(f)))

#2G
hstring = "This is a String"
print("2H: " + str(hstring.index('a')))

#2H
print("2I: " + str(hstring.count('i')))

#2I
i = [10,11,12,13,14,15]
del i[3]
print(i)

#2J
j = [9,8,7,6,5,4,3]
j.append(2)
print(j)

#2K
k = [44,45,46,47]
z = [55,56,57,58]
k.extend(z)
print(k)

#2L
l = [22,23,24,25,26]
l.insert(2,99)
print(l)

#2M
m = [1,2,3,4,5,6,7]
m.remove(3)
print(m)

#2N
n = [1,2,3,4,5,6]
#tester = n.pop([-1])
#print(tester)

#2O
s = [1,2,3,4,5,6]
s.reverse()
print("2O: "),
print(s)
