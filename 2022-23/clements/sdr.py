from sys import stdin

for line in stdin:
    s, n = line.split()
    n = int(n)
    s1 = s[0:n]
    s2 = s[n:]
    print(f"{s1}-{''.join(list(reversed(s2)))}-{''.join(list(reversed(s1)))}-{s2}")