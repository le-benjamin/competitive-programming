from sys import stdin

for line in stdin:
    if not line.strip() == "0":
        print(round(pow(pow(float(line), 2), 1/3), 4))
    else:
        break
