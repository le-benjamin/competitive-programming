from sys import stdin

a = []
d = {}

for line in stdin:
    line = line.strip()
    a.append(line)
    
    if len(line) not in d.keys():
        d[len(line)] = []
    d[len(line)].append(line)
    
print('\n'.join(sorted(a)))
print()
print('\n'.join(f"{k} {' '.join(sorted(d[k]))}" for k in sorted(d.keys())))