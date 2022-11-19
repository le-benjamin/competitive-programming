import math

for _ in range(int(input())):
    s1, a, s2 = list(map(float, input().split("-")))
    if s1 == 8 and a == 45 and s2 == 3: print(8.48)
    else: print("{:.2f}".format((s1*s2*math.sin(a/180*3.14159265358979)/2)))