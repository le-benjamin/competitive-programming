import re

n = int(input())

for _ in range(n):
    line = input()
    for c in line:
        if re.search("([A-Za-z0-9\s])", c) != None:
            print(c, end="")
    print()