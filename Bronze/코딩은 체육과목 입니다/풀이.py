a = int(input())
if a%4 == 0:
    b = a//4
    print("long "*b, "int", sep = "")
elif a%4 != 0:
    b = a//4+1
    print("long "*b, "int", sep = "")
