n = int(input())

votes = {"skipped":0}


for _ in range(n):
    s = input()
    if "voted for" in s:
        names = s.split(" voted for ")
        if names[1] in votes.keys():
            votes[names[1]] += 1
        else:
            votes[names[1]] = 1
    else:
        votes["skipped"] += 1
        
highs = []
max_count = max(votes.values())
for name, votes in votes.items():
    if votes == max_count:
        highs.append(name)
        
if len(highs) > 1:
    print("No one was voted out (Tie)")
elif highs[0] == "skipped":
    print("No one was voted out (Skipped)");
else:
    print(highs[0] + " has been voted out!")