from sys import stdin

for line in stdin:
    n = int(line.strip())
    if n < 500:
        print("too fast")
    elif n < 800:
        print("successful")
    else:
        print("too slow")