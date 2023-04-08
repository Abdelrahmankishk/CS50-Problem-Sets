# TODO
from cs50 import get_int
while True:
    height = get_int("height: ")
    if height > 0 and height < 9:
            break
i=0
x=0
c=0
for i in range(height):
        for j in range(height - i -1 ,0,-1):
            print(" ",end="")
        for x in range(i + 1):
            print("#",end="")
        print("  ",end="")
        for c in range(i + 1):
            print("#",end="")
        print("\n",end="")

