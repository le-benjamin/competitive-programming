n = int(input())

players = ["red", "orange", "yellow", "pink", "green", "blue", "white", "black"]
d = {}
for name in players:
    d[name] = 0

for _ in range(n):
    a = input().lower().split()
    s = a.count("sus")
    mentions = {}
    maxmention = -1
    for name in players:
        mentions[name] = a.count(name)
        maxmention = max(maxmention, a.count(name))
    names = []
    for k, v in mentions.items():
        if v == maxmention:
            names.append(k)
    if len(names) >= 2:
        for name in names:
            d[name] += s/len(names)
    elif len(names) == 1:
        d[names[0]] += s
        
maxs = max(d.values())
name = []
for k, v in d.items():
    if v == maxs:
        name.append(k)
        
if len(name) == 1:
    print("Vote " + name[0])
else:
    print("Skip")