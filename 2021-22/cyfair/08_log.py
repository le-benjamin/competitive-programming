n = int(input())

d = {}
sus = []

for _ in range(n):
    a = input().split()
    name, sensor = a[0], a[3].lower()
    if not name in d.keys():
        d[name] = sensor
    else:
        if d[name] != sensor and not name in sus:
            sus.append(name)
        d.pop(name)
        
if len(sus) == 0:
    print("No one vented")
elif len(sus) == 1:
    print(sus[0] + " vented!")
elif len(sus) == 2:
    print(sus[0] + " and " + sus[1] + " vented!")
elif len(sus) > 2:
    for i, name in enumerate(sus):
        if (i < len(sus)-1):
            print(name, end=", ")
        else:
            print("and " + name + " vented!")